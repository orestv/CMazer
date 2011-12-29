#ifndef MAIN_WINDOW_CPP
#define MAIN_WINDOW_CPP

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "MainWindow.h"
#include "MazeWidget.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    initComponents();

}

void MainWindow::initComponents() {
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    QHBoxLayout *pControlsLayout = new QHBoxLayout();

    pbtnGenerate = new QPushButton("&Generate");
    pControlsLayout->addWidget(pbtnGenerate);

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
}

void MainWindow::generateMaze() {
    pMazeModel->regenerate(80, 30);
    pMazeWidget->repaint();
}

#endif
