#ifndef AIRBLOCK_H
#define AIRBLOCK_H
#include "commons.h"

class AirBlock : public Block
{
    public:
        AirBlock();
        virtual ~AirBlock();

        void draw() override;

    protected:

    private:
};

#endif // AIRBLOCK_H
