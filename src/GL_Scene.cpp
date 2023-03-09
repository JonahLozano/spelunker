#include "GL_Scene.h"
#include "GL_Light.h"
#include <player.h>
#include <enms.h>


Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs();
parallax *prLx = new parallax();
player *ply = new player();
enms *en = new enms();

GL_Scene::GL_Scene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GL_Scene::~GL_Scene()
{
    //dtor
}
int GL_Scene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // glColor3f(1.0,0.0,0.0);

    // TEAPOT
//    glPushMatrix();
//        // glutSolidTeapot(1.5f);
//        // make your own player class & Model model into a class instead of global
//        glScaled(0.25,0.25,0.25);
//        glTranslatef(0,0,-8.0f);
//        myFirstModel->drawModel();
//    glPopMatrix();

    // PARALAX
    glPushMatrix();
        glScaled(3.333,3.333,1);
        prLx->drawSquare(screenWidth,screenHeight);
        // prLx->scroll(true,"x",0.0025);
    glPopMatrix();

    // PLAYER
    glPushMatrix();
        ply->drawPlayer();
    glPopMatrix();

    // ENEMY
    glPushMatrix();
        en->drawEnemy();
    glPopMatrix();


    return true;
}

int GL_Scene::GLinit()
{
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GL_Light Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    myFirstModel->modelInit("images/ny1.jpg");
    prLx->initParallax("images/para.jpg");
    // ply->playerInit("images/sprite.png",1,8);
    ply->playerInit("images/eg-1.png",4,6);
    en->initEnemy("images/mon.png",2,7);

    // KbMs->mdl = myFirstModel; // copy model to mdl

    return true;
}

void GL_Scene::GLReSize(GLsizei width, GLsizei height)
{
    screenWidth = width;
    screenHeight = height;

    float ratio = (float)width/(float)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,ratio,0.1,1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GL_Scene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;

    switch(uMsg){
    case WM_KEYDOWN:
        KbMs->keyPressed(myFirstModel);
        KbMs->keyEnv(prLx,0.005);
        KbMs->keyPlayer(ply);
        break;
    case WM_KEYUP:
        ply->actions(ply->IDLE);
        KbMs->mouseBtnUp();
        break;
    case WM_LBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;
    case WM_RBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;
    case WM_MBUTTONDOWN:
        break;

    case WM_LBUTTONUP:
    case WM_RBUTTONUP:
    case WM_MBUTTONUP:
        KbMs->mouseBtnUp();
        break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(myFirstModel,LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(myFirstModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;

    case WM_MOUSELEAVE:
        break;
    }
}
