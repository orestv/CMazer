#ifndef MAZE_WIDGET_H
#define MAZE_WIDGET_H

#include <QWidget>
#include <QPaintEvent>

class MazeWidget : public QWidget {
    Q_OBJECT
    public:
        MazeWidget(QWidget *parent = 0);

    protected:
        void paintEvent(QPaintEvent *pEvent);
};

#endif
