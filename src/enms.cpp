#include "enms.h"

enms::enms()
{
    //ctor

    ePos.x = ePos.y = 0.0f;
    ePos.z = -3.0f;

    eSize.x = 1.0f;
    eSize.y = 0.5f;


    eRota.x = eRota.y = eRota.z = 0.0f;

    eSpeed.x = 0.01f;
    eSpeed.y = 0.01f;
}

enms::~enms()
{
    //dtor
}
void enms::drawEnemy()
{
    glPushMatrix();
        tLoad->binder(tex);
        glTranslated(ePos.x,ePos.y,ePos.z);
        glRotatef(eRota.x,1.0f,0.0,0.0f);
        glRotatef(eRota.y,0.0f,1.0,0.0f);
        glRotatef(eRota.z,0.0f,0.0,1.0f);
        glScalef(eSize.x,eSize.y,1.0f);

        glBegin(GL_QUADS);
            glTexCoord2f(xMin,yMin);
            glVertex3f(1.0,1.0,0.0);

            glTexCoord2f(xMax,yMin);
            glVertex3f(-1.0,1.0,0.0);

            glTexCoord2f(xMax,yMax);
            glVertex3f(-1.0,-1.0,0.0);

            glTexCoord2f(xMin,yMax);
            glVertex3f(1.0,-1.0,0.0);
        glEnd();
    glPopMatrix();
}

void enms::placeEnemy(vec3)
{

}

void enms::initEnemy(char* fileName, int vfrm, int hfrm)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    vFrames = vfrm;
    hFrames = hfrm;

    xMax = 1.0/hFrames;
    xMin = 0.0;
    yMax = 1.0/vFrames;
    yMin = 0.0;

    tLoad->loadTexture(fileName,tex);
}

void enms::actions(acts)
{

}
