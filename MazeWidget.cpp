
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
    painter.setBrush(Qt::white);

    painter.drawRect(1, 1, this->width()-2, this->height()-2);

    int nMargin = 5;

    int nWidgetWidth = this->width() - 2*nMargin;
    int nWidgetHeight = this->height() - 2*nMargin;
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

QSize MazeWidget::sizeHint() const {
    return QSize(800, 600);
}




