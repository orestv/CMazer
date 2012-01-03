#ifndef MAIN_WINDOW_CPP
#define MAIN_WINDOW_CPP

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPrintDialog>
#include <QPainter>
#include "MainWindow.h"
#include "MazeWidget.h"
#include "MazePainter.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    initComponents();

}

void MainWindow::initComponents() {
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    QHBoxLayout *pControlsLayout = new QHBoxLayout();

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
    pMazeModel->regenerate(80, 30);
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
