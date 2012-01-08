#include "QSizePicker.h"
#include <QGridLayout>
#include <QLabel>
#include <math.h>

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

QSizePicker::QSizePicker(int maxWidth, double scale, QWidget *parent)
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
    QObject::connect(m_pchkConnect, SIGNAL(clicked(bool)), this, SLOT(scaleCheckboxClicked(bool)));

    pLayout->addWidget(plblWidth, 0, 0);
    pLayout->addWidget(m_pspWidth, 0, 1);
    pLayout->addWidget(plblHeight, 1, 0);
    pLayout->addWidget(m_pspHeight, 1, 1);
    pLayout->addWidget(m_pchkConnect, 0, 2, 2, 1);

    this->setLayout(pLayout);
}

QSize QSizePicker::value() const {
    return QSize(m_pspWidth->value(), m_pspHeight->value());
}

void QSizePicker::setValue(QSize value) {
    m_pspHeight->setValue(value.height());
    m_pspWidth->setValue(value.width());
}

void QSizePicker::updateHeightSpinBox(int width) {
    int height = width/scale;
    m_pspHeight->setValue(height);
}

void QSizePicker::scaleCheckboxClicked(bool bChecked) {
    if (bChecked) {
        cachedHeight = m_pspHeight->value();
        QObject::connect(m_pspWidth, SIGNAL(valueChanged(int)), this, SLOT(updateHeightSpinBox(int)));
        updateHeightSpinBox(m_pspWidth->value());
    } else {
        QObject::disconnect(m_pspWidth, SIGNAL(valueChanged(int)), this, SLOT(updateHeightSpinBox(int)));
        m_pspHeight->setValue(cachedHeight);
    }
    m_pspHeight->setEnabled(!bChecked);
}
