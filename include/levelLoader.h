#ifndef LEVELLOADER_H
#define LEVELLOADER_H
#include "commons.h"


class levelLoader
{
    public:
        // structors
        levelLoader();
        virtual ~levelLoader();

        // properties
        vector<std::vector<std::unique_ptr<Block>>> levelData;

        // methods
        void loadCSV(const string&);
        void drawLevel();

    protected:

    private:
};

#endif // LEVELLOADER_H
