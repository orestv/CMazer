#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QPushButton>

class MainWindow : public QWidget {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);

    protected:
        void initComponents();

    private:
        QPushButton *pQuitButton;

};


#endif
