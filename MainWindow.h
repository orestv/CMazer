#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>
#include "MazeWidget.h"
#include "MazeModel.h"
#include <QPrinter>
#include <QSpinBox>
#include <QCheckBox>

class MainWindow : public QWidget {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
    public slots:
        void generateMaze();
        void showPrintDialog();
        void A4CheckboxClicked(bool bChecked);
        void updateHeight();

    protected:
        void initComponents();
        void print(QPrinter &printer);
        void setProportionalHeight();

    private:
        QPushButton *pbtnQuit;
        QPushButton *pbtnGenerate;
        QPushButton *pbtnPrint;
        QSpinBox *pspWidth;
        QSpinBox *pspHeight;
        QCheckBox *pchkA4Scale;
        int nCachedHeight;      //saved when A4 checkbox is checked,
                                //restored when it's unchecked

        MazeModel *pMazeModel;
        MazeWidget *pMazeWidget;

};


#endif
