/********************************************************************************
** Form generated from reading UI file 'okno.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNO_H
#define UI_OKNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Okno
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSpinBox *interwalGeneratora;
    QLabel *etykietaFps;
    QLabel *fps;
    QCheckBox *pokazGraf;

    void setupUi(QMainWindow *Okno)
    {
        if (Okno->objectName().isEmpty())
            Okno->setObjectName(QString::fromUtf8("Okno"));
        Okno->setEnabled(true);
        Okno->resize(750, 750);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Okno->sizePolicy().hasHeightForWidth());
        Okno->setSizePolicy(sizePolicy);
        Okno->setMinimumSize(QSize(750, 750));
        Okno->setMaximumSize(QSize(750, 750));
        centralwidget = new QWidget(Okno);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 720, 201, 20));
        interwalGeneratora = new QSpinBox(centralwidget);
        interwalGeneratora->setObjectName(QString::fromUtf8("interwalGeneratora"));
        interwalGeneratora->setGeometry(QRect(380, 720, 51, 22));
        interwalGeneratora->setMinimum(1);
        interwalGeneratora->setMaximum(5);
        etykietaFps = new QLabel(centralwidget);
        etykietaFps->setObjectName(QString::fromUtf8("etykietaFps"));
        etykietaFps->setGeometry(QRect(10, 720, 21, 20));
        fps = new QLabel(centralwidget);
        fps->setObjectName(QString::fromUtf8("fps"));
        fps->setGeometry(QRect(40, 720, 31, 20));
        pokazGraf = new QCheckBox(centralwidget);
        pokazGraf->setObjectName(QString::fromUtf8("pokazGraf"));
        pokazGraf->setGeometry(QRect(70, 720, 70, 17));
        Okno->setCentralWidget(centralwidget);

        retranslateUi(Okno);

        QMetaObject::connectSlotsByName(Okno);
    } // setupUi

    void retranslateUi(QMainWindow *Okno)
    {
        Okno->setWindowTitle(QCoreApplication::translate("Okno", "Miasto", nullptr));
        label->setText(QCoreApplication::translate("Okno", "Interwa\305\202 generatora pojazd\303\263w (sekundy)", nullptr));
        etykietaFps->setText(QCoreApplication::translate("Okno", "FPS:", nullptr));
        fps->setText(QCoreApplication::translate("Okno", "0", nullptr));
        pokazGraf->setText(QCoreApplication::translate("Okno", "Poka\305\274 graf", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Okno: public Ui_Okno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNO_H
