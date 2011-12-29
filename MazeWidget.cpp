
#include "MazeWidget.h"
#include <QPainter>
#include "math.h"

MazeWidget::MazeWidget(QWidget *parent) : QWidget(parent){
    pModel = 0;
}

MazeWidget::~MazeWidget() {
    if (pModel != 0)
        delete pModel;
}

void MazeWidget::setModel(MazeModel *pModel) {
    this->pModel = pModel;
}

MazeModel* MazeWidget::model() {
    return pModel;
}

void MazeWidget::paintEvent(QPaintEvent *pEvent) {
    QPainter painter(this);

    int nMargin = 5;

    int nWidgetWidth = this->width() - 2*nMargin;
    int nWidgetHeight = this->height() - 2*nMargin;
    if (!pModel->hasMaze())
        return;

    int nMazeWidth = pModel->width();
    int nMazeHeight = pModel->height();

    int nCellSize = std::min(nWidgetWidth/nMazeWidth,
                             nWidgetHeight/nMazeHeight);

    QPoint ptNW, ptNE, ptSW, ptSE;

    for (int row = 0; row < nMazeHeight; row++) {
        for (int col = 0; col < nMazeWidth; col++) {
            ptNW = QPoint(col * nCellSize + nMargin,
                          row * nCellSize + nMargin);
            ptNE = QPoint((col+1) * nCellSize + nMargin,
                          row * nCellSize + nMargin);
            ptSW = QPoint(col * nCellSize + nMargin,
                          (row+1) * nCellSize + nMargin);
            ptSE = QPoint((col+1) * nCellSize + nMargin,
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

QSize MazeWidget::sizeHint() const {
    return QSize(800, 600);
}




