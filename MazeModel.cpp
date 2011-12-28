#include "MazeModel.h"
#include "MazeGenerator.h"

MazeModel::MazeModel() {
    pMaze = 0;
}

MazeModel::~MazeModel() {
    if (pMaze)
        delete pMaze;
}

void MazeModel::regenerate(int width, int height) {
    if (pMaze)
        delete pMaze;
    pMaze = new Maze(width, height);
}
