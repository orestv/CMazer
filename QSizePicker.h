#ifndef QSIZE_PICKER_H
#define QSIZE_PICKER_H

#include <QWidget>
#include <QSpinBox>
#include <QCheckBox>

class QSizePicker : public QWidget {
Q_OBJECT
    public:
        QSizePicker(QWidget *parent = 0);
        QSizePicker(int maxWidth, int maxHeight, QWidget *parent = 0);
        QSizePicker(int maxWidth, float scale, QWidget *parent = 0);

        QSize value();
    private:
        static const int MIN_WIDTH = 15;
        void initComponents();
        void setSpinBounds(int maxWidth, int maxHeight, float scale);

        int maxWidth;
        int maxHeight;
        float scale;

        QSpinBox *m_pspWidth;
        QSpinBox *m_pspHeight;
        QCheckBox *m_pchkConnect;
};

#endif
