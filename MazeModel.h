#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include "Maze.h"

class MazeModel {
    public:
        MazeModel();
        ~MazeModel();
        void regenerate(int width, int height);

        enum Direction {UP = 1, RIGHT = 2, DOWN = 4, LEFT = 8};

        int width();
        int height();
        int cellWalls(int col, int row);
        bool hasMaze();


    private:
        Maze *pMaze;
};


#endif
