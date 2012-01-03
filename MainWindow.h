#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "MazeWidget.h"
#include "MazeModel.h"
#include <QPrinter>

class MainWindow : public QWidget {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
    public slots:
        void generateMaze();
        void showPrintDialog();

    protected:
        void initComponents();
        void print(QPrinter &printer);

    private:
        QPushButton *pbtnQuit;
        QPushButton *pbtnGenerate;
        QPushButton *pbtnPrint;

        MazeModel *pMazeModel;
        MazeWidget *pMazeWidget;

};


#endif
