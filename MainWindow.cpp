#ifndef MAIN_WINDOW_CPP
#define MAIN_WINDOW_CPP

#include <QApplication>
#include <QVBoxLayout>
#include "MainWindow.h"
#include "MazeWidget.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    initComponents();

}

void MainWindow::initComponents() {
    QVBoxLayout *pLayout = new QVBoxLayout();

    pQuitButton = new QPushButton("&Quit");
    pLayout->addWidget(pQuitButton);

    MazeWidget *pMaze = new MazeWidget(this);
    pLayout->addWidget(pMaze);

    connect(pQuitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    this->setLayout(pLayout);
}

#endif
