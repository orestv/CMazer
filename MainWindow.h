#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "MazeWidget.h"
#include "MazeModel.h"

class MainWindow : public QWidget {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
public slots:
        void generateMaze();

    protected:
        void initComponents();

    private:
        QPushButton *pbtnQuit;
        QPushButton *pbtnGenerate;

        MazeModel *pMazeModel;
        MazeWidget *pMazeWidget;

};


#endif
