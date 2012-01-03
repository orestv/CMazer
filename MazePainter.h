#ifndef MAZE_PAINTER_H
#define MAZE_PAINTER_H

#include <QPainter>
#include "MazeModel.h"

class MazePainter {
    public:
	    static void paint(MazeModel *pModel, QPainter &painter);
};

#endif
