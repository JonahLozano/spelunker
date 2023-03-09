#ifndef ENMS_H
#define ENMS_H
#include <GL/gl.h>
#include <textureLoader.h>
#include <commons.h>


class enms
{
    public:
        enms();
        virtual ~enms();

        void drawEnemy();
        void placeEnemy(vec3);
        void initEnemy(char*,int,int); // char* for filename; and ints, int for 2d frames

        enum acts{IDLE,WALKLEFT,WALKRIGHT,JUMP,ATTACK,DIE};

        void actions(acts); //

        int hFrames; // horizontal frames
        int vFrames; // vertical frames

        float xMax,yMax,xMin,yMin; // for the texture
        vec3 ePos; // position of the enemy
        vec2 eSize;
        vec2 eSpeed; // moving speed

        vec3 eRota;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

    protected:

    private:
};

#endif // ENMS_H
