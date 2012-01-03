#include "MazePainter.h"

void MazePainter::paint(MazeModel *pModel, QPainter &painter) {

    QRect rSize = painter.viewport();

    if (!pModel->hasMaze())
        return;

    int nMazeWidth = pModel->width();
    int nMazeHeight = pModel->height();

    float nCellSize = std::min((float)rSize.width()/nMazeWidth,
                             (float)rSize.height()/nMazeHeight);

    //draw the big left and top walls of the maze
    QLineF wall;
    wall.setP1(QPointF(0, 0));
    wall.setP2(QPointF(nCellSize, 0));
    for (int col = 0; col < nMazeWidth; col++) {
        if (pModel->cellWalls(col, 0) & MazeModel::UP)
            painter.drawLine(wall);
        wall.translate(nCellSize, 0);
    }

    wall.setP1(QPointF(0, 0));
    wall.setP2(QPointF(0, nCellSize));
    for (int row = 0; row < nMazeHeight; row++) {
        if (pModel->cellWalls(0, row) & MazeModel::LEFT)
            painter.drawLine(wall);
        wall.translate(0, nCellSize);
    }

    //draw the rest of the maze's walls
    for (int row = 0; row < nMazeHeight; row++) {
        QLineF wallDown(0, (row+1)*nCellSize, nCellSize, (row+1)*nCellSize);
        QLineF wallRight(nCellSize, row*nCellSize, nCellSize, (row+1)*nCellSize);

        for (int col = 0; col < nMazeWidth; col++) {
            int walls = pModel->cellWalls(col, row);
            if (walls & MazeModel::RIGHT)
                painter.drawLine(wallRight);
            if (walls & MazeModel::DOWN)
                painter.drawLine(wallDown);

            wallDown.translate(nCellSize, 0);
            wallRight.translate(nCellSize, 0);
        }
    }
}
