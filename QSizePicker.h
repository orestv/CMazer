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
        QSizePicker(int maxWidth, double scale, QWidget *parent = 0);

        QSize value() const;
        void setValue(QSize size);
    private slots:
        void updateHeightSpinBox(int width);
        void scaleCheckboxClicked(bool bClicked);
    private:
        static const int MIN_WIDTH = 15;
        void initComponents();
        void setSpinBounds(int maxWidth, int maxHeight, float scale);

        int maxWidth;
        int maxHeight;
        double scale;
        int cachedHeight;

        QSpinBox *m_pspWidth;
        QSpinBox *m_pspHeight;
        QCheckBox *m_pchkConnect;
};

#endif
