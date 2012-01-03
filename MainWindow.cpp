#ifndef MAIN_WINDOW_CPP
#define MAIN_WINDOW_CPP

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPrintDialog>
#include <QPainter>
#include "MainWindow.h"
#include "MazeWidget.h"
#include "MazePainter.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    initComponents();

}

void MainWindow::initComponents() {
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    QHBoxLayout *pControlsLayout = new QHBoxLayout();
    QGridLayout *pSizeLayout = new QGridLayout();

    pSizeLayout->addWidget(new QLabel("Width"), 0, 0);
    pspWidth = new QSpinBox();
    pspWidth->setMinimum(12);
    pspWidth->setMaximum(150);
    pspWidth->setValue(70);
    pSizeLayout->addWidget(pspWidth, 0, 1);

    pSizeLayout->addWidget(new QLabel("Height"), 1, 0);
    pspHeight = new QSpinBox();
    pspHeight->setMinimum(12);
    pspHeight->setMaximum(150);
    pspHeight->setValue(50);
    pSizeLayout->addWidget(pspHeight, 1, 1);

    pControlsLayout->addLayout(pSizeLayout);

    pbtnGenerate = new QPushButton("&Generate");
    pControlsLayout->addWidget(pbtnGenerate);

    pbtnPrint = new QPushButton("&Print");
    pControlsLayout->addWidget(pbtnPrint);

    pbtnQuit = new QPushButton("&Quit");
    pControlsLayout->addWidget(pbtnQuit);


    pMainLayout->addLayout(pControlsLayout);

    pMazeWidget = new MazeWidget(this);
    pMainLayout->addWidget(pMazeWidget);

    this->setLayout(pMainLayout);

    pMazeModel = new MazeModel();
    pMazeWidget->setModel(pMazeModel);


    connect(pbtnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(pbtnGenerate, SIGNAL(clicked()), this, SLOT(generateMaze()));
    connect(pbtnPrint, SIGNAL(clicked()), this, SLOT(showPrintDialog()));
}

void MainWindow::generateMaze() {
    int width = pspWidth->value();
    int height = pspHeight->value();;
    pMazeModel->regenerate(width, height);
    pMazeWidget->repaint();
}

void MainWindow::showPrintDialog() {
    QPrinter printer;
    QPrintDialog *pDialog = new QPrintDialog(&printer);
    if (pDialog->exec() == QDialog::Accepted)
        print(printer);
}

void MainWindow::print(QPrinter &printer) {
    QPainter painter;
    painter.begin(&printer);

    MazePainter::paint(pMazeModel, painter);

    painter.end();
}

#endif
