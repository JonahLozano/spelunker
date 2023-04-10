#ifndef BLOCK_H
#define BLOCK_H
#include "commons.h"
//#include "GL/gl.h"
//#include "textureLoader.h"

class Block
{
    public:
        Block();
        virtual ~Block();

        virtual void draw();

//        void drawBlock();
//        void initBlock(GLuint,int,int);
//        void blockTexture(char*);
//        void placeBlock(float,float);
//
//        GLuint tex;
//        textureLoader *tLoad = new textureLoader();

    protected:

    private:
};

#endif // BLOCK_H
