
#include "MazeWidget.h"
#include <QPainter>
#include <QWMatrix>
#include "math.h"
#include "MazePainter.h"

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
    painter.drawRect(painter.viewport());

    if (!pModel->hasMaze())
        return;

    int nMargin = 5;
    float fX, fY;
    fX = 1. - (float)nMargin*2/this->width();
    fY = 1. - (float)nMargin*2/this->height();

    painter.scale(fX, fY);
    painter.translate(nMargin, nMargin);

    MazePainter::paint(pModel, painter);
}

QSize MazeWidget::sizeHint() const {
    return QSize(800, 600);
}




