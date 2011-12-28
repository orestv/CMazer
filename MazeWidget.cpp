
#include "MazeWidget.h"
#include <QPainter>

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
    painter.drawLine(100, 100, 300, 300);
}

QSize MazeWidget::sizeHint() const {
    return QSize(800, 600);

}




