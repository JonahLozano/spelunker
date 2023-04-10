#include "levelLoader.h"

levelLoader::levelLoader()
{
    //ctor
}

levelLoader::~levelLoader()
{
    //dtor
}
void levelLoader::loadCSV(const string& filename)
{
    cout << "loading level..." << endl;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<unique_ptr<block>> row;

        while (getline(ss, cell, ',')) {
            if (cell == "boundary") {
                row.push_back(make_unique<BoundaryBlock>());
            } else if (cell == "air") {
                row.push_back(make_unique<AirBlock>());
            } else if (cell == "cloud") {
                row.push_back(make_unique<CloudBlock>());
            } else if (cell == "chest") {
                row.push_back(make_unique<ChestBlock>());
            } else if (cell == "grass") {
                row.push_back(make_unique<GrassBlock>());
            } else if (cell == "spawn") {
                row.push_back(make_unique<SpawnBlock>());
            } else if (cell == "finish") {
                row.push_back(make_unique<FinishBlock>());
            } else if (cell == "enemy") {
                row.push_back(make_unique<EnemyBlock>());
            }
        }
        levelData.push_back(move(row));
    }
    file.close();
    cout << "loading complete." << endl;
}

void levelLoader::drawLevel()
{
    for (const auto& row : levelData) {
            for (const auto& block : row) {
                // block->draw();
            }
            cout << endl;
        }
}
