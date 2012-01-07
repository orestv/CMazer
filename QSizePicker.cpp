#include "QSizePicker.h"
#include <QGridLayout>
#include <QLabel>

QSizePicker::QSizePicker(QWidget *parent) : QWidget(parent){
    initComponents();
}

QSizePicker::QSizePicker(int maxWidth, int maxHeight, QWidget *parent) 
:QWidget(parent) {
    initComponents();
    this->maxWidth = maxWidth;
    this->maxHeight = maxHeight;
    this->scale = (float)maxWidth/maxHeight;

    setSpinBounds(maxWidth, maxHeight, scale);
}

QSizePicker::QSizePicker(int maxWidth, float scale, QWidget *parent)
:QWidget(parent) {
    initComponents();
    this->maxWidth = maxWidth;
    this->scale = scale;
    this->maxHeight = maxWidth/scale;

    setSpinBounds(maxWidth, maxHeight, scale);
}

void QSizePicker::setSpinBounds(int maxWidth, int maxHeight, float scale) {
    m_pspWidth->setMaximum(maxWidth);
    m_pspHeight->setMaximum(maxHeight);
    m_pspWidth->setMinimum(MIN_WIDTH);
    m_pspHeight->setMinimum(MIN_WIDTH/scale);
}

void QSizePicker::initComponents() {
    QGridLayout *pLayout = new QGridLayout();
    m_pspWidth = new QSpinBox();
    m_pspHeight = new QSpinBox();
    QLabel *plblWidth = new QLabel("Width");
    QLabel *plblHeight = new QLabel("Height");
    m_pchkConnect = new QCheckBox("Keep A4 scale");

    pLayout->addWidget(plblWidth, 0, 0);
    pLayout->addWidget(m_pspWidth, 0, 1);
    pLayout->addWidget(plblHeight, 1, 0);
    pLayout->addWidget(m_pspHeight, 1, 1);
    pLayout->addWidget(m_pchkConnect, 0, 2, 2, 1);

    this->setLayout(pLayout);
}
