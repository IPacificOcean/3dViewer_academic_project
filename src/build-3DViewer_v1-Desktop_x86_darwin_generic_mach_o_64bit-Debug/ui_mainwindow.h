/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glviewer.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    GLviewer *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *y_t;
    QDoubleSpinBox *doubleSpinBox_y_t;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *z_t;
    QDoubleSpinBox *doubleSpinBox_z_t;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *scale;
    QDoubleSpinBox *doubleSpinBox_Scale;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *x_r;
    QDoubleSpinBox *doubleSpinBox_x_r;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *y_r;
    QDoubleSpinBox *doubleSpinBox_y_r;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *x_r_2;
    QDoubleSpinBox *doubleSpinBox_z_r;
    QLabel *translate;
    QLabel *rotate;
    QLabel *projection;
    QRadioButton *radioButton_frustum;
    QRadioButton *radioButton_ortho;
    QLabel *transform;
    QLabel *paint;
    QLabel *point;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_10;
    QLabel *color_point;
    QComboBox *comboBox_point_color;
    QLabel *line_7;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *form_line;
    QComboBox *comboBox_line_form;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *color_line;
    QComboBox *comboBox_line_color;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *size_point;
    QSpinBox *spinBox_point_size;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *width_line;
    QSpinBox *spinBox_line_width;
    QLabel *background;
    QWidget *layoutWidget_12;
    QHBoxLayout *horizontalLayout_15;
    QLabel *color_backround;
    QComboBox *comboBox_background_color;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QLabel *info;
    QLabel *vertexes;
    QLabel *coun_vertexes;
    QLabel *count_facets;
    QLabel *facets;
    QLabel *filename;
    QLabel *name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *openFile;
    QPushButton *load_setting;
    QPushButton *update;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *x_t;
    QDoubleSpinBox *doubleSpinBox_x_t;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *form_point;
    QComboBox *comboBox_point_form;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QPushButton *save_img;
    QPushButton *save_gif;
    QPushButton *save_sattings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1500, 1000);
        MainWindow->setMinimumSize(QSize(1500, 1000));
        MainWindow->setMaximumSize(QSize(1500, 1000));
        MainWindow->setMouseTracking(false);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new GLviewer(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        widget->setGeometry(QRect(350, 70, 800, 800));
        widget->setMinimumSize(QSize(800, 800));
        widget->setMaximumSize(QSize(800, 800));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 420, 91, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        y_t = new QLabel(layoutWidget);
        y_t->setObjectName(QString::fromUtf8("y_t"));

        horizontalLayout_3->addWidget(y_t);

        doubleSpinBox_y_t = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_y_t->setObjectName(QString::fromUtf8("doubleSpinBox_y_t"));
        doubleSpinBox_y_t->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_y_t->setMinimum(0.000000000000000);
        doubleSpinBox_y_t->setSingleStep(0.010000000000000);
        doubleSpinBox_y_t->setValue(0.050000000000000);

        horizontalLayout_3->addWidget(doubleSpinBox_y_t);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(70, 460, 91, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        z_t = new QLabel(layoutWidget_2);
        z_t->setObjectName(QString::fromUtf8("z_t"));

        horizontalLayout_4->addWidget(z_t);

        doubleSpinBox_z_t = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_z_t->setObjectName(QString::fromUtf8("doubleSpinBox_z_t"));
        doubleSpinBox_z_t->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_z_t->setMinimum(0.000000000000000);
        doubleSpinBox_z_t->setSingleStep(0.010000000000000);
        doubleSpinBox_z_t->setValue(0.050000000000000);

        horizontalLayout_4->addWidget(doubleSpinBox_z_t);

        layoutWidget_6 = new QWidget(centralwidget);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(80, 510, 191, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        scale = new QLabel(layoutWidget_6);
        scale->setObjectName(QString::fromUtf8("scale"));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        scale->setFont(font);

        horizontalLayout_8->addWidget(scale);

        doubleSpinBox_Scale = new QDoubleSpinBox(layoutWidget_6);
        doubleSpinBox_Scale->setObjectName(QString::fromUtf8("doubleSpinBox_Scale"));
        doubleSpinBox_Scale->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_Scale->setMinimum(0.000000000000000);
        doubleSpinBox_Scale->setSingleStep(0.010000000000000);
        doubleSpinBox_Scale->setValue(0.050000000000000);

        horizontalLayout_8->addWidget(doubleSpinBox_Scale);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(180, 380, 91, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        x_r = new QLabel(layoutWidget_3);
        x_r->setObjectName(QString::fromUtf8("x_r"));

        horizontalLayout_5->addWidget(x_r);

        doubleSpinBox_x_r = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_x_r->setObjectName(QString::fromUtf8("doubleSpinBox_x_r"));
        doubleSpinBox_x_r->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_x_r->setMinimum(0.000000000000000);
        doubleSpinBox_x_r->setSingleStep(0.010000000000000);
        doubleSpinBox_x_r->setValue(0.050000000000000);

        horizontalLayout_5->addWidget(doubleSpinBox_x_r);

        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(180, 420, 91, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        y_r = new QLabel(layoutWidget_4);
        y_r->setObjectName(QString::fromUtf8("y_r"));

        horizontalLayout_6->addWidget(y_r);

        doubleSpinBox_y_r = new QDoubleSpinBox(layoutWidget_4);
        doubleSpinBox_y_r->setObjectName(QString::fromUtf8("doubleSpinBox_y_r"));
        doubleSpinBox_y_r->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_y_r->setMinimum(0.000000000000000);
        doubleSpinBox_y_r->setSingleStep(0.010000000000000);
        doubleSpinBox_y_r->setValue(0.050000000000000);

        horizontalLayout_6->addWidget(doubleSpinBox_y_r);

        layoutWidget_5 = new QWidget(centralwidget);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(180, 460, 91, 31));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        x_r_2 = new QLabel(layoutWidget_5);
        x_r_2->setObjectName(QString::fromUtf8("x_r_2"));

        horizontalLayout_7->addWidget(x_r_2);

        doubleSpinBox_z_r = new QDoubleSpinBox(layoutWidget_5);
        doubleSpinBox_z_r->setObjectName(QString::fromUtf8("doubleSpinBox_z_r"));
        doubleSpinBox_z_r->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_z_r->setMinimum(0.000000000000000);
        doubleSpinBox_z_r->setSingleStep(0.010000000000000);
        doubleSpinBox_z_r->setValue(0.050000000000000);

        horizontalLayout_7->addWidget(doubleSpinBox_z_r);

        translate = new QLabel(centralwidget);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setGeometry(QRect(77, 350, 71, 20));
        translate->setFont(font);
        rotate = new QLabel(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(200, 350, 58, 16));
        rotate->setFont(font);
        projection = new QLabel(centralwidget);
        projection->setObjectName(QString::fromUtf8("projection"));
        projection->setGeometry(QRect(130, 140, 101, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        projection->setFont(font1);
        radioButton_frustum = new QRadioButton(centralwidget);
        radioButton_frustum->setObjectName(QString::fromUtf8("radioButton_frustum"));
        radioButton_frustum->setGeometry(QRect(70, 180, 99, 20));
        radioButton_frustum->setFont(font);
        radioButton_ortho = new QRadioButton(centralwidget);
        radioButton_ortho->setObjectName(QString::fromUtf8("radioButton_ortho"));
        radioButton_ortho->setGeometry(QRect(200, 180, 99, 20));
        radioButton_ortho->setFont(font);
        transform = new QLabel(centralwidget);
        transform->setObjectName(QString::fromUtf8("transform"));
        transform->setGeometry(QRect(130, 310, 101, 21));
        transform->setFont(font1);
        paint = new QLabel(centralwidget);
        paint->setObjectName(QString::fromUtf8("paint"));
        paint->setGeometry(QRect(1240, 140, 101, 21));
        paint->setFont(font1);
        point = new QLabel(centralwidget);
        point->setObjectName(QString::fromUtf8("point"));
        point->setGeometry(QRect(1240, 200, 58, 16));
        point->setFont(font);
        layoutWidget_7 = new QWidget(centralwidget);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(1240, 260, 191, 32));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        color_point = new QLabel(layoutWidget_7);
        color_point->setObjectName(QString::fromUtf8("color_point"));

        horizontalLayout_10->addWidget(color_point);

        comboBox_point_color = new QComboBox(layoutWidget_7);
        comboBox_point_color->addItem(QString());
        comboBox_point_color->addItem(QString());
        comboBox_point_color->addItem(QString());
        comboBox_point_color->setObjectName(QString::fromUtf8("comboBox_point_color"));

        horizontalLayout_10->addWidget(comboBox_point_color);

        line_7 = new QLabel(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(1240, 370, 58, 16));
        line_7->setFont(font);
        layoutWidget_8 = new QWidget(centralwidget);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(1240, 390, 191, 32));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        form_line = new QLabel(layoutWidget_8);
        form_line->setObjectName(QString::fromUtf8("form_line"));

        horizontalLayout_11->addWidget(form_line);

        comboBox_line_form = new QComboBox(layoutWidget_8);
        comboBox_line_form->addItem(QString());
        comboBox_line_form->addItem(QString());
        comboBox_line_form->addItem(QString());
        comboBox_line_form->setObjectName(QString::fromUtf8("comboBox_line_form"));

        horizontalLayout_11->addWidget(comboBox_line_form);

        layoutWidget_9 = new QWidget(centralwidget);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(1240, 430, 191, 32));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        color_line = new QLabel(layoutWidget_9);
        color_line->setObjectName(QString::fromUtf8("color_line"));

        horizontalLayout_12->addWidget(color_line);

        comboBox_line_color = new QComboBox(layoutWidget_9);
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->addItem(QString());
        comboBox_line_color->setObjectName(QString::fromUtf8("comboBox_line_color"));

        horizontalLayout_12->addWidget(comboBox_line_color);

        layoutWidget_10 = new QWidget(centralwidget);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(1240, 300, 191, 31));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_10);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        size_point = new QLabel(layoutWidget_10);
        size_point->setObjectName(QString::fromUtf8("size_point"));

        horizontalLayout_13->addWidget(size_point);

        spinBox_point_size = new QSpinBox(layoutWidget_10);
        spinBox_point_size->setObjectName(QString::fromUtf8("spinBox_point_size"));

        horizontalLayout_13->addWidget(spinBox_point_size);

        layoutWidget_11 = new QWidget(centralwidget);
        layoutWidget_11->setObjectName(QString::fromUtf8("layoutWidget_11"));
        layoutWidget_11->setGeometry(QRect(1240, 470, 191, 31));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget_11);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        width_line = new QLabel(layoutWidget_11);
        width_line->setObjectName(QString::fromUtf8("width_line"));

        horizontalLayout_14->addWidget(width_line);

        spinBox_line_width = new QSpinBox(layoutWidget_11);
        spinBox_line_width->setObjectName(QString::fromUtf8("spinBox_line_width"));

        horizontalLayout_14->addWidget(spinBox_line_width);

        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(1240, 550, 81, 16));
        background->setFont(font);
        layoutWidget_12 = new QWidget(centralwidget);
        layoutWidget_12->setObjectName(QString::fromUtf8("layoutWidget_12"));
        layoutWidget_12->setGeometry(QRect(1240, 570, 191, 32));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_12);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        color_backround = new QLabel(layoutWidget_12);
        color_backround->setObjectName(QString::fromUtf8("color_backround"));

        horizontalLayout_15->addWidget(color_backround);

        comboBox_background_color = new QComboBox(layoutWidget_12);
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->addItem(QString());
        comboBox_background_color->setObjectName(QString::fromUtf8("comboBox_background_color"));

        horizontalLayout_15->addWidget(comboBox_background_color);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(70, 250, 201, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(1240, 170, 201, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(1240, 350, 201, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(1240, 520, 201, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(160, 390, 20, 91));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(680, 882, 201, 41));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        info = new QLabel(centralwidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(680, 880, 101, 21));
        info->setFont(font1);
        vertexes = new QLabel(centralwidget);
        vertexes->setObjectName(QString::fromUtf8("vertexes"));
        vertexes->setGeometry(QRect(680, 950, 58, 16));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        vertexes->setFont(font2);
        coun_vertexes = new QLabel(centralwidget);
        coun_vertexes->setObjectName(QString::fromUtf8("coun_vertexes"));
        coun_vertexes->setGeometry(QRect(780, 950, 58, 16));
        coun_vertexes->setFont(font2);
        count_facets = new QLabel(centralwidget);
        count_facets->setObjectName(QString::fromUtf8("count_facets"));
        count_facets->setGeometry(QRect(780, 930, 58, 16));
        count_facets->setFont(font2);
        facets = new QLabel(centralwidget);
        facets->setObjectName(QString::fromUtf8("facets"));
        facets->setGeometry(QRect(680, 930, 58, 16));
        facets->setFont(font2);
        filename = new QLabel(centralwidget);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(780, 910, 58, 16));
        filename->setFont(font2);
        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(680, 910, 58, 16));
        name->setFont(font2);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 30, 481, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openFile = new QPushButton(layoutWidget1);
        openFile->setObjectName(QString::fromUtf8("openFile"));

        horizontalLayout->addWidget(openFile);

        load_setting = new QPushButton(layoutWidget1);
        load_setting->setObjectName(QString::fromUtf8("load_setting"));

        horizontalLayout->addWidget(load_setting);

        update = new QPushButton(layoutWidget1);
        update->setObjectName(QString::fromUtf8("update"));

        horizontalLayout->addWidget(update);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(70, 380, 91, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        x_t = new QLabel(layoutWidget2);
        x_t->setObjectName(QString::fromUtf8("x_t"));

        horizontalLayout_2->addWidget(x_t);

        doubleSpinBox_x_t = new QDoubleSpinBox(layoutWidget2);
        doubleSpinBox_x_t->setObjectName(QString::fromUtf8("doubleSpinBox_x_t"));
        doubleSpinBox_x_t->setProperty("showGroupSeparator", QVariant(false));
        doubleSpinBox_x_t->setMinimum(0.000000000000000);
        doubleSpinBox_x_t->setSingleStep(0.010000000000000);
        doubleSpinBox_x_t->setValue(0.050000000000000);

        horizontalLayout_2->addWidget(doubleSpinBox_x_t);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(1240, 220, 191, 32));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        form_point = new QLabel(layoutWidget3);
        form_point->setObjectName(QString::fromUtf8("form_point"));

        horizontalLayout_9->addWidget(form_point);

        comboBox_point_form = new QComboBox(layoutWidget3);
        comboBox_point_form->addItem(QString());
        comboBox_point_form->addItem(QString());
        comboBox_point_form->addItem(QString());
        comboBox_point_form->setObjectName(QString::fromUtf8("comboBox_point_form"));

        horizontalLayout_9->addWidget(comboBox_point_form);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(70, 630, 201, 131));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        save_img = new QPushButton(widget1);
        save_img->setObjectName(QString::fromUtf8("save_img"));

        verticalLayout->addWidget(save_img);

        save_gif = new QPushButton(widget1);
        save_gif->setObjectName(QString::fromUtf8("save_gif"));

        verticalLayout->addWidget(save_gif);

        save_sattings = new QPushButton(widget1);
        save_sattings->setObjectName(QString::fromUtf8("save_sattings"));

        verticalLayout->addWidget(save_sattings);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3dViwer 1.0", nullptr));
        y_t->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        z_t->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        x_r->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        y_r->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        x_r_2->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        projection->setText(QCoreApplication::translate("MainWindow", "Projection:", nullptr));
        radioButton_frustum->setText(QCoreApplication::translate("MainWindow", "Frustum", nullptr));
        radioButton_ortho->setText(QCoreApplication::translate("MainWindow", "Ortho", nullptr));
        transform->setText(QCoreApplication::translate("MainWindow", "Transform:", nullptr));
        paint->setText(QCoreApplication::translate("MainWindow", "Paint:", nullptr));
        point->setText(QCoreApplication::translate("MainWindow", "Point", nullptr));
        color_point->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        comboBox_point_color->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        comboBox_point_color->setItemText(1, QCoreApplication::translate("MainWindow", "green", nullptr));
        comboBox_point_color->setItemText(2, QCoreApplication::translate("MainWindow", "blue", nullptr));

        line_7->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        form_line->setText(QCoreApplication::translate("MainWindow", "form", nullptr));
        comboBox_line_form->setItemText(0, QCoreApplication::translate("MainWindow", "empty", nullptr));
        comboBox_line_form->setItemText(1, QCoreApplication::translate("MainWindow", "solid", nullptr));
        comboBox_line_form->setItemText(2, QCoreApplication::translate("MainWindow", "dashed", nullptr));

        color_line->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        comboBox_line_color->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        comboBox_line_color->setItemText(1, QCoreApplication::translate("MainWindow", "green", nullptr));
        comboBox_line_color->setItemText(2, QCoreApplication::translate("MainWindow", "blue", nullptr));

        size_point->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        width_line->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        background->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        color_backround->setText(QCoreApplication::translate("MainWindow", "color", nullptr));
        comboBox_background_color->setItemText(0, QCoreApplication::translate("MainWindow", "red", nullptr));
        comboBox_background_color->setItemText(1, QCoreApplication::translate("MainWindow", "green", nullptr));
        comboBox_background_color->setItemText(2, QCoreApplication::translate("MainWindow", "blue", nullptr));

        info->setText(QCoreApplication::translate("MainWindow", "Info:", nullptr));
        vertexes->setText(QCoreApplication::translate("MainWindow", "vertexes:", nullptr));
        coun_vertexes->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        count_facets->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        facets->setText(QCoreApplication::translate("MainWindow", "facets:", nullptr));
        filename->setText(QCoreApplication::translate("MainWindow", "filename", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "name:", nullptr));
        openFile->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        load_setting->setText(QCoreApplication::translate("MainWindow", "Load setting", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        x_t->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        form_point->setText(QCoreApplication::translate("MainWindow", "form", nullptr));
        comboBox_point_form->setItemText(0, QCoreApplication::translate("MainWindow", "empty", nullptr));
        comboBox_point_form->setItemText(1, QCoreApplication::translate("MainWindow", "smooth", nullptr));
        comboBox_point_form->setItemText(2, QCoreApplication::translate("MainWindow", "square", nullptr));

        save_img->setText(QCoreApplication::translate("MainWindow", "Save img", nullptr));
        save_gif->setText(QCoreApplication::translate("MainWindow", "Save gif", nullptr));
        save_sattings->setText(QCoreApplication::translate("MainWindow", "Save setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
