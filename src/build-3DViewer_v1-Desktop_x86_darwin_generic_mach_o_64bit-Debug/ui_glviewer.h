/********************************************************************************
** Form generated from reading UI file 'glviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLVIEWER_H
#define UI_GLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_glviewer
{
public:

    void setupUi(QDialog *glviewer)
    {
        if (glviewer->objectName().isEmpty())
            glviewer->setObjectName(QString::fromUtf8("glviewer"));
        glviewer->resize(400, 300);

        retranslateUi(glviewer);

        QMetaObject::connectSlotsByName(glviewer);
    } // setupUi

    void retranslateUi(QDialog *glviewer)
    {
        glviewer->setWindowTitle(QCoreApplication::translate("glviewer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class glviewer: public Ui_glviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLVIEWER_H
