#include "player.h"

player::player()
{
    //ctor


    verts[0].x = -0.5f;
    verts[0].y = -0.5f;
    verts[0].z = -1.0f;

    verts[1].x = 0.5f;
    verts[1].y = -0.5f;
    verts[1].z = -1.0f;

    verts[2].x = 0.5f;
    verts[2].y = 0.5f;
    verts[2].z = -1.0f;

    verts[3].x = -0.5f;
    verts[3].y = 0.5f;
    verts[3].z = -1.0f;

    runSpeed = 0;
    jumpSpeed = 0;
    actionTrigger = IDLE;

    pPos.x = 0;
    pPos.y = -0.5;
    pPos.z = -3;

    playerDir = 'R';
}

player::~player()
{
    //dtor
}
vec3 player::scaleSize()
{

}

void player::drawPlayer()
{
    tLoad->binder(tex);
    glTranslated(pPos.x,pPos.y,pPos.z);
    glBegin(GL_QUADS);
        glTexCoord2f(xMin,yMax);
        glVertex3f(verts[0].x,verts[0].y,verts[0].z);

        glTexCoord2f(xMax,yMax);
        glVertex3f(verts[1].x,verts[1].y,verts[1].z);

        glTexCoord2f(xMax,yMin);
        glVertex3f(verts[2].x,verts[2].y,verts[2].z);

        glTexCoord2f(xMin,yMin);
        glVertex3f(verts[3].x,verts[3].y,verts[3].z);
    glEnd();
}

void player::playerInit(char* fileName, int vfrm, int hfrm)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vfrm;
    hFrames = hfrm;

    xMax = 1.0/hFrames;
    xMin = 0.0;
    yMax = 1.0/vFrames;
    yMin = 0.0;

//    std::cout << "vfrm: " << vfrm << "    hfrm: " << hfrm << std::endl;

    tLoad->loadTexture(fileName,tex);
}

void player::actions(acts action)
{
    switch(action){
    case IDLE:
        if(playerDir == 'R')
        {
            xMax = 1.0/hFrames;
            xMin = 0.0;
            yMin = 0.0;
            yMax = 1.0/vFrames;
        }
        if(playerDir == 'L')
        {
            xMin = 1.0/hFrames;
            xMax = 0.0;
            yMin = 0.0;
            yMax = 1.0/vFrames;
        }

        break;

    case WALKLEFT:
    // go through all frames
        if(playerDir != 'L')
        {
            float tmp;
            tmp = xMin;
            xMin = xMax;
            xMax = tmp;

            playerDir = 'L';
        }

        xMin += 1/(float)hFrames;
        xMax += 1/(float)hFrames;

        if(xMin >= 1.0)
        {
            xMax = 0.0;
            xMin = 1.0/(float)hFrames;

            yMin += 1.0/(float)vFrames;
            yMax += 1.0/(float)vFrames;
        }
        break;
    case WALKRIGHT:
        // go through all frames
        if(playerDir != 'R')
        {
            float tmp;
            tmp = xMin;
            xMin = xMax;
            xMax = tmp;

            playerDir = 'R';
        }

        xMin += 1/(float)hFrames;
        xMax += 1/(float)hFrames;

        if(xMin >= 1.0)
        {
            xMin = 0.0;
            xMax = 1.0/(float)hFrames;

            yMin += 1.0/(float)vFrames;
            yMax += 1.0/(float)vFrames;
        }
        break;
    case JUMP:
        break;
    }
}
