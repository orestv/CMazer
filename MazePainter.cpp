#include "MazePainter.h"

void MazePainter::paint(MazeModel *pModel, QPainter &painter) {

    QRect rSize = painter.viewport();

    if (!pModel->hasMaze())
        return;

    int nMazeWidth = pModel->width();
    int nMazeHeight = pModel->height();

    float nCellSize = std::min((float)rSize.width()/nMazeWidth,
                             (float)rSize.height()/nMazeHeight);

    QPointF ptNW, ptNE, ptSW, ptSE;

    for (int row = 0; row < nMazeHeight; row++) {
        for (int col = 0; col < nMazeWidth; col++) {
            ptNW = QPointF(col * nCellSize,
                          row * nCellSize);
            ptNE = QPointF((col+1) * nCellSize,
                          row * nCellSize);
            ptSW = QPointF(col * nCellSize,
                          (row+1) * nCellSize);
            ptSE = QPointF((col+1) * nCellSize,
                          (row+1) * nCellSize);

            int walls = pModel->cellWalls(col, row);
            if (walls & MazeModel::UP)
                painter.drawLine(ptNW, ptNE);
            if (walls & MazeModel::RIGHT)
                painter.drawLine(ptNE, ptSE);
            if (walls & MazeModel::DOWN)
                painter.drawLine(ptSW, ptSE);
            if (walls & MazeModel::LEFT)
                painter.drawLine(ptNW, ptSW);
        }
    }
}
