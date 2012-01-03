
#include "MazeWidget.h"
#include <QPainter>
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
    MazePainter::paint(pModel, painter);
}

QSize MazeWidget::sizeHint() const {
    return QSize(800, 600);
}




