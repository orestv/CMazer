#ifndef MAZE_WIDGET_H
#define MAZE_WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include "MazeModel.h"

class MazeWidget : public QWidget {
    Q_OBJECT
    public:
        MazeWidget(QWidget *parent = 0);
        QSize sizeHint() const;

        void setModel(MazeModel *pModel);
        MazeModel* model();

        virtual ~MazeWidget();
    protected:
        void paintEvent(QPaintEvent *pEvent);

    private:
        MazeModel *pModel;
};

#endif
