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
    MazeGenerator::generate(*pMaze);
}

bool MazeModel::hasMaze() {
    return (pMaze != 0);
}

int MazeModel::width() {
    if (!hasMaze())
        throw "Maze not yet generated!";
    return pMaze->width();
}

int MazeModel::height() {
    if (!hasMaze())
        throw "Maze not yet generated!";
    return pMaze->height();
}

int MazeModel::cellWalls(int col, int row) {
    if (col < 0 || row < 0 || col >= this->width() || row >= this->width())
        throw "Cell coordinates out of bounds: cellWalls";
    int result = 0;
    if (pMaze->hasWall(col, row, Maze::UP))
        result |= MazeModel::UP;
    if (pMaze->hasWall(col, row, Maze::DOWN))
        result |= MazeModel::DOWN;
    if (pMaze->hasWall(col, row, Maze::LEFT))
        result |= MazeModel::LEFT;
    if (pMaze->hasWall(col, row, Maze::RIGHT))
        result |= MazeModel::RIGHT;
    return result;
}
