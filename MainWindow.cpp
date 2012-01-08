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
#include <math.h>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    initComponents();
}

void MainWindow::initComponents() {
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    QGridLayout *pControlsLayout = new QGridLayout();
    QGridLayout *pSizeLayout = new QGridLayout();

    pSizePicker = new QSizePicker(250, sqrt(2.));
    pSizePicker->setValue(QSize(90, 75));

    pSizeLayout->addWidget(pSizePicker, 0, 0, 2, 1);

    pControlsLayout->addLayout(pSizeLayout, 0, 0, 2, 1);

    pbtnGenerate = new QPushButton("&Generate");
    pControlsLayout->addWidget(pbtnGenerate, 0, 1);

    pbtnPrint = new QPushButton("&Print");
    pbtnPrint->setEnabled(false);
    pControlsLayout->addWidget(pbtnPrint, 1, 1);

    pbtnQuit = new QPushButton("&Quit");
    pControlsLayout->addWidget(pbtnQuit, 0, 2, 2, 1);


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
    QSize size = pSizePicker->value();
    pMazeModel->regenerate(size.width(), size.height());
    pMazeWidget->repaint();
    pbtnPrint->setEnabled(true);
}

void MainWindow::showPrintDialog() {
    QPrinter printer;
    printer.setDocName("Maze");
    QPrintDialog *pDialog = new QPrintDialog(&printer);
    if (pDialog->exec() == QDialog::Accepted)
        print(printer);
}

void MainWindow::print(QPrinter &printer) {
    printer.setOrientation(QPrinter::Landscape);
    QPainter painter;
    painter.begin(&printer);

    painter.setPen(QPen(QBrush(QColor(0, 0, 0)), 1.5, Qt::SolidLine, Qt::FlatCap));

    MazePainter::paint(pMazeModel, painter);

    painter.end();
}


#endif
