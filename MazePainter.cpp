#include "MazePainter.h"

void MazePainter::paint(MazeModel *pModel, QPainter &painter) {
    QRect rSize = painter.viewport();
    painter.setBrush(Qt::white);

    painter.drawRect(rSize);

    int nMargin = 5;

    int nWidgetWidth = rSize.width() - 2*nMargin;
    int nWidgetHeight = rSize.height() - 2*nMargin;
    if (!pModel->hasMaze())
        return;

    int nMazeWidth = pModel->width();
    int nMazeHeight = pModel->height();

    float nCellSize = std::min((float)nWidgetWidth/nMazeWidth,
                             (float)nWidgetHeight/nMazeHeight);

    QPointF ptNW, ptNE, ptSW, ptSE;

    for (int row = 0; row < nMazeHeight; row++) {
        for (int col = 0; col < nMazeWidth; col++) {
            ptNW = QPointF(col * nCellSize + nMargin,
                          row * nCellSize + nMargin);
            ptNE = QPointF((col+1) * nCellSize + nMargin,
                          row * nCellSize + nMargin);
            ptSW = QPointF(col * nCellSize + nMargin,
                          (row+1) * nCellSize + nMargin);
            ptSE = QPointF((col+1) * nCellSize + nMargin,
                          (row+1) * nCellSize + nMargin);

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
