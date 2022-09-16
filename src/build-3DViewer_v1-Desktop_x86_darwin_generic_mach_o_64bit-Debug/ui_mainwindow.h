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
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
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
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *scale;
    QDoubleSpinBox *doubleSpinBox_Scale;
    QLabel *translate;
    QLabel *rotate;
    QLabel *projection;
    QRadioButton *radioButton_frustum;
    QRadioButton *radioButton_ortho;
    QLabel *transform;
    QLabel *paint;
    QLabel *point;
    QLabel *line_7;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_11;
    QLabel *form_line;
    QComboBox *comboBox_line_form;
    QWidget *layoutWidget_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *size_point;
    QSpinBox *spinBox_point_size;
    QWidget *layoutWidget_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *width_line;
    QSpinBox *spinBox_line_width;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_6;
    QLabel *info;
    QLabel *vertexes;
    QLabel *coun_vertexes;
    QLabel *count_facets;
    QLabel *facets;
    QLabel *filename;
    QLabel *name;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *openFile;
    QPushButton *load_setting;
    QPushButton *update;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *dx;
    QLabel *x_t;
    QSpinBox *rdx;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *form_point;
    QComboBox *comboBox_point_form;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QPushButton *Pthoto;
    QPushButton *stop_and_save_GIF;
    QPushButton *save_sattings;
    QWidget *layoutWidget_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *scale_2;
    QDoubleSpinBox *modelScale;
    QSlider *horizontalSlider_dx;
    QDial *dial_rdx;
    QDial *dial_rdy;
    QSlider *horizontalSlider_dy;
    QWidget *layoutWidget_14;
    QHBoxLayout *horizontalLayout_17;
    QSpinBox *dy;
    QLabel *y;
    QSpinBox *rdy;
    QDial *dial_rdz;
    QWidget *layoutWidget_15;
    QHBoxLayout *horizontalLayout_19;
    QSpinBox *dz;
    QLabel *z;
    QSpinBox *rdz;
    QSlider *horizontalSlider_dz;
    QPushButton *color;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *colorPoint;
    QRadioButton *colorLine;
    QRadioButton *colorBackground;
    QPushButton *optimization;
    QPushButton *gebug_cactus;
    QLabel *label_Timer_GIF;
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
        layoutWidget_6 = new QWidget(centralwidget);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(60, 600, 191, 31));
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
        doubleSpinBox_Scale->setDecimals(7);
        doubleSpinBox_Scale->setMinimum(0.000000000000000);
        doubleSpinBox_Scale->setSingleStep(0.010000000000000);
        doubleSpinBox_Scale->setValue(0.500000000000000);

        horizontalLayout_8->addWidget(doubleSpinBox_Scale);

        translate = new QLabel(centralwidget);
        translate->setObjectName(QString::fromUtf8("translate"));
        translate->setGeometry(QRect(77, 300, 71, 20));
        translate->setFont(font);
        rotate = new QLabel(centralwidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(200, 300, 58, 16));
        rotate->setFont(font);
        projection = new QLabel(centralwidget);
        projection->setObjectName(QString::fromUtf8("projection"));
        projection->setGeometry(QRect(130, 70, 101, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        projection->setFont(font1);
        radioButton_frustum = new QRadioButton(centralwidget);
        radioButton_frustum->setObjectName(QString::fromUtf8("radioButton_frustum"));
        radioButton_frustum->setGeometry(QRect(70, 110, 99, 20));
        radioButton_frustum->setFont(font);
        radioButton_ortho = new QRadioButton(centralwidget);
        radioButton_ortho->setObjectName(QString::fromUtf8("radioButton_ortho"));
        radioButton_ortho->setGeometry(QRect(200, 110, 99, 20));
        radioButton_ortho->setFont(font);
        transform = new QLabel(centralwidget);
        transform->setObjectName(QString::fromUtf8("transform"));
        transform->setGeometry(QRect(130, 260, 101, 21));
        transform->setFont(font1);
        paint = new QLabel(centralwidget);
        paint->setObjectName(QString::fromUtf8("paint"));
        paint->setGeometry(QRect(1240, 140, 101, 21));
        paint->setFont(font1);
        point = new QLabel(centralwidget);
        point->setObjectName(QString::fromUtf8("point"));
        point->setGeometry(QRect(1240, 200, 58, 16));
        point->setFont(font);
        line_7 = new QLabel(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(1240, 400, 58, 16));
        line_7->setFont(font);
        layoutWidget_8 = new QWidget(centralwidget);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(1240, 420, 191, 32));
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

        layoutWidget_10 = new QWidget(centralwidget);
        layoutWidget_10->setObjectName(QString::fromUtf8("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(1240, 270, 191, 31));
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

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(70, 180, 201, 16));
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
        line_4->setGeometry(QRect(1240, 560, 201, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
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
        coun_vertexes->setGeometry(QRect(780, 950, 100, 16));
        coun_vertexes->setFont(font2);
        count_facets = new QLabel(centralwidget);
        count_facets->setObjectName(QString::fromUtf8("count_facets"));
        count_facets->setGeometry(QRect(780, 930, 100, 16));
        count_facets->setFont(font2);
        facets = new QLabel(centralwidget);
        facets->setObjectName(QString::fromUtf8("facets"));
        facets->setGeometry(QRect(680, 930, 58, 16));
        facets->setFont(font2);
        filename = new QLabel(centralwidget);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(780, 910, 100, 16));
        filename->setFont(font2);
        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(680, 910, 58, 16));
        name->setFont(font2);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(500, 30, 481, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        openFile = new QPushButton(layoutWidget);
        openFile->setObjectName(QString::fromUtf8("openFile"));

        horizontalLayout->addWidget(openFile);

        load_setting = new QPushButton(layoutWidget);
        load_setting->setObjectName(QString::fromUtf8("load_setting"));

        horizontalLayout->addWidget(load_setting);

        update = new QPushButton(layoutWidget);
        update->setObjectName(QString::fromUtf8("update"));

        horizontalLayout->addWidget(update);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(70, 330, 191, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        dx = new QSpinBox(layoutWidget1);
        dx->setObjectName(QString::fromUtf8("dx"));
        dx->setMinimum(-100);

        horizontalLayout_2->addWidget(dx);

        x_t = new QLabel(layoutWidget1);
        x_t->setObjectName(QString::fromUtf8("x_t"));
        x_t->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(x_t);

        rdx = new QSpinBox(layoutWidget1);
        rdx->setObjectName(QString::fromUtf8("rdx"));
        rdx->setMinimum(-360);
        rdx->setMaximum(360);

        horizontalLayout_2->addWidget(rdx);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1240, 220, 191, 32));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        form_point = new QLabel(layoutWidget2);
        form_point->setObjectName(QString::fromUtf8("form_point"));

        horizontalLayout_9->addWidget(form_point);

        comboBox_point_form = new QComboBox(layoutWidget2);
        comboBox_point_form->addItem(QString());
        comboBox_point_form->addItem(QString());
        comboBox_point_form->addItem(QString());
        comboBox_point_form->setObjectName(QString::fromUtf8("comboBox_point_form"));

        horizontalLayout_9->addWidget(comboBox_point_form);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 750, 201, 131));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Pthoto = new QPushButton(layoutWidget3);
        Pthoto->setObjectName(QString::fromUtf8("Pthoto"));

        verticalLayout->addWidget(Pthoto);

        stop_and_save_GIF = new QPushButton(layoutWidget3);
        stop_and_save_GIF->setObjectName(QString::fromUtf8("stop_and_save_GIF"));

        verticalLayout->addWidget(stop_and_save_GIF);

        save_sattings = new QPushButton(layoutWidget3);
        save_sattings->setObjectName(QString::fromUtf8("save_sattings"));

        verticalLayout->addWidget(save_sattings);

        layoutWidget_13 = new QWidget(centralwidget);
        layoutWidget_13->setObjectName(QString::fromUtf8("layoutWidget_13"));
        layoutWidget_13->setGeometry(QRect(60, 640, 191, 31));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_13);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        scale_2 = new QLabel(layoutWidget_13);
        scale_2->setObjectName(QString::fromUtf8("scale_2"));
        scale_2->setFont(font);

        horizontalLayout_16->addWidget(scale_2);

        modelScale = new QDoubleSpinBox(layoutWidget_13);
        modelScale->setObjectName(QString::fromUtf8("modelScale"));
        modelScale->setProperty("showGroupSeparator", QVariant(false));
        modelScale->setMinimum(0.000000000000000);
        modelScale->setMaximum(100.000000000000000);
        modelScale->setSingleStep(1.000000000000000);
        modelScale->setValue(1.000000000000000);

        horizontalLayout_16->addWidget(modelScale);

        horizontalSlider_dx = new QSlider(centralwidget);
        horizontalSlider_dx->setObjectName(QString::fromUtf8("horizontalSlider_dx"));
        horizontalSlider_dx->setGeometry(QRect(40, 370, 121, 25));
        horizontalSlider_dx->setMinimum(-100);
        horizontalSlider_dx->setMaximum(100);
        horizontalSlider_dx->setOrientation(Qt::Horizontal);
        dial_rdx = new QDial(centralwidget);
        dial_rdx->setObjectName(QString::fromUtf8("dial_rdx"));
        dial_rdx->setGeometry(QRect(210, 360, 50, 50));
        dial_rdx->setMaximum(360);
        dial_rdx->setPageStep(1);
        dial_rdx->setWrapping(false);
        dial_rdx->setNotchesVisible(true);
        dial_rdy = new QDial(centralwidget);
        dial_rdy->setObjectName(QString::fromUtf8("dial_rdy"));
        dial_rdy->setGeometry(QRect(210, 440, 50, 50));
        dial_rdy->setMaximum(360);
        dial_rdy->setWrapping(false);
        dial_rdy->setNotchesVisible(true);
        horizontalSlider_dy = new QSlider(centralwidget);
        horizontalSlider_dy->setObjectName(QString::fromUtf8("horizontalSlider_dy"));
        horizontalSlider_dy->setGeometry(QRect(40, 450, 121, 25));
        horizontalSlider_dy->setMinimum(-100);
        horizontalSlider_dy->setMaximum(100);
        horizontalSlider_dy->setOrientation(Qt::Horizontal);
        layoutWidget_14 = new QWidget(centralwidget);
        layoutWidget_14->setObjectName(QString::fromUtf8("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(70, 410, 191, 31));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget_14);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        dy = new QSpinBox(layoutWidget_14);
        dy->setObjectName(QString::fromUtf8("dy"));
        dy->setMinimum(-100);

        horizontalLayout_17->addWidget(dy);

        y = new QLabel(layoutWidget_14);
        y->setObjectName(QString::fromUtf8("y"));
        y->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(y);

        rdy = new QSpinBox(layoutWidget_14);
        rdy->setObjectName(QString::fromUtf8("rdy"));
        rdy->setMinimum(-360);
        rdy->setMaximum(360);

        horizontalLayout_17->addWidget(rdy);

        dial_rdz = new QDial(centralwidget);
        dial_rdz->setObjectName(QString::fromUtf8("dial_rdz"));
        dial_rdz->setGeometry(QRect(210, 530, 50, 50));
        dial_rdz->setMaximum(360);
        dial_rdz->setWrapping(false);
        dial_rdz->setNotchesVisible(true);
        layoutWidget_15 = new QWidget(centralwidget);
        layoutWidget_15->setObjectName(QString::fromUtf8("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(70, 500, 191, 31));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget_15);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        dz = new QSpinBox(layoutWidget_15);
        dz->setObjectName(QString::fromUtf8("dz"));
        dz->setMinimum(-100);

        horizontalLayout_19->addWidget(dz);

        z = new QLabel(layoutWidget_15);
        z->setObjectName(QString::fromUtf8("z"));
        z->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(z);

        rdz = new QSpinBox(layoutWidget_15);
        rdz->setObjectName(QString::fromUtf8("rdz"));
        rdz->setMinimum(-360);
        rdz->setMaximum(360);

        horizontalLayout_19->addWidget(rdz);

        horizontalSlider_dz = new QSlider(centralwidget);
        horizontalSlider_dz->setObjectName(QString::fromUtf8("horizontalSlider_dz"));
        horizontalSlider_dz->setGeometry(QRect(40, 540, 121, 25));
        horizontalSlider_dz->setMinimum(-100);
        horizontalSlider_dz->setMaximum(100);
        horizontalSlider_dz->setOrientation(Qt::Horizontal);
        color = new QPushButton(centralwidget);
        color->setObjectName(QString::fromUtf8("color"));
        color->setGeometry(QRect(1240, 670, 191, 41));
        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(1210, 630, 239, 20));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        colorPoint = new QRadioButton(layoutWidget4);
        colorPoint->setObjectName(QString::fromUtf8("colorPoint"));
        QFont font3;
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setItalic(true);
        colorPoint->setFont(font3);

        horizontalLayout_3->addWidget(colorPoint);

        colorLine = new QRadioButton(layoutWidget4);
        colorLine->setObjectName(QString::fromUtf8("colorLine"));
        colorLine->setFont(font);

        horizontalLayout_3->addWidget(colorLine);

        colorBackground = new QRadioButton(layoutWidget4);
        colorBackground->setObjectName(QString::fromUtf8("colorBackground"));
        colorBackground->setFont(font);

        horizontalLayout_3->addWidget(colorBackground);

        optimization = new QPushButton(centralwidget);
        optimization->setObjectName(QString::fromUtf8("optimization"));
        optimization->setGeometry(QRect(100, 680, 131, 32));
        gebug_cactus = new QPushButton(centralwidget);
        gebug_cactus->setObjectName(QString::fromUtf8("gebug_cactus"));
        gebug_cactus->setGeometry(QRect(40, 900, 100, 32));
        label_Timer_GIF = new QLabel(centralwidget);
        label_Timer_GIF->setObjectName(QString::fromUtf8("label_Timer_GIF"));
        label_Timer_GIF->setGeometry(QRect(250, 800, 41, 17));
        label_Timer_GIF->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider_dx, &QSlider::valueChanged, dx, &QSpinBox::setValue);
        QObject::connect(dial_rdx, &QDial::valueChanged, rdx, &QSpinBox::setValue);
        QObject::connect(dx, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(rdx, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(horizontalSlider_dy, &QSlider::valueChanged, dy, &QSpinBox::setValue);
        QObject::connect(horizontalSlider_dz, &QSlider::valueChanged, dz, &QSpinBox::setValue);
        QObject::connect(dy, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(dz, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(rdy, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(rdz, &QSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));
        QObject::connect(dial_rdy, &QDial::valueChanged, rdy, &QSpinBox::setValue);
        QObject::connect(dial_rdz, &QDial::valueChanged, rdz, &QSpinBox::setValue);
        QObject::connect(modelScale, &QDoubleSpinBox::valueChanged, update, qOverload<>(&QPushButton::click));

        comboBox_line_form->setCurrentIndex(1);
        comboBox_point_form->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3dViwer 1.0", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        translate->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        rotate->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        projection->setText(QCoreApplication::translate("MainWindow", "Projection:", nullptr));
        radioButton_frustum->setText(QCoreApplication::translate("MainWindow", "Frustum", nullptr));
        radioButton_ortho->setText(QCoreApplication::translate("MainWindow", "Ortho", nullptr));
        transform->setText(QCoreApplication::translate("MainWindow", "Transform:", nullptr));
        paint->setText(QCoreApplication::translate("MainWindow", "Paint:", nullptr));
        point->setText(QCoreApplication::translate("MainWindow", "Point", nullptr));
        line_7->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        form_line->setText(QCoreApplication::translate("MainWindow", "form", nullptr));
        comboBox_line_form->setItemText(0, QCoreApplication::translate("MainWindow", "empty", nullptr));
        comboBox_line_form->setItemText(1, QCoreApplication::translate("MainWindow", "solid", nullptr));
        comboBox_line_form->setItemText(2, QCoreApplication::translate("MainWindow", "dashed", nullptr));

        size_point->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        width_line->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
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

        comboBox_point_form->setPlaceholderText(QCoreApplication::translate("MainWindow", "rty", nullptr));
        Pthoto->setText(QCoreApplication::translate("MainWindow", "Save img", nullptr));
        stop_and_save_GIF->setText(QCoreApplication::translate("MainWindow", "Save gif", nullptr));
        save_sattings->setText(QCoreApplication::translate("MainWindow", "Save setting", nullptr));
        scale_2->setText(QCoreApplication::translate("MainWindow", "Scale model", nullptr));
        y->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        z->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        color->setText(QCoreApplication::translate("MainWindow", "COLOR", nullptr));
        colorPoint->setText(QCoreApplication::translate("MainWindow", "Point", nullptr));
        colorLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        colorBackground->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        optimization->setText(QCoreApplication::translate("MainWindow", "Scale optimization", nullptr));
        gebug_cactus->setText(QCoreApplication::translate("MainWindow", "debag cactus", nullptr));
        label_Timer_GIF->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
