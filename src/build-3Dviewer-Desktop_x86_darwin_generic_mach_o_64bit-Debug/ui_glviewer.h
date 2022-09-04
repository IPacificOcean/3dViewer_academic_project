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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GLviewer
{
public:

    void setupUi(QWidget *GLviewer)
    {
        if (GLviewer->objectName().isEmpty())
            GLviewer->setObjectName(QString::fromUtf8("GLviewer"));
        GLviewer->resize(800, 600);

        retranslateUi(GLviewer);

        QMetaObject::connectSlotsByName(GLviewer);
    } // setupUi

    void retranslateUi(QWidget *GLviewer)
    {
        GLviewer->setWindowTitle(QCoreApplication::translate("GLviewer", "GLviewer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GLviewer: public Ui_GLviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLVIEWER_H
