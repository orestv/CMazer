#ifndef MAZE_MODEL_H
#define MAZE_MODEL_H

#include "Maze.h"

class MazeModel {
    public:
        MazeModel();
        ~MazeModel();
        void regenerate(int width, int height);

    private:
        Maze *pMaze;
};


#endif
