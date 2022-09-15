#include "glviewer.h"
//#include <clocale.h>


GLviewer::GLviewer(QWidget *parent)
    : QOpenGLWidget(parent)
{
//    ui->setupUi(this);
    setWindowTitle("3Dviewer");
    setGeometry(400, 200, 1200, 900);
    vertex = {0, nullptr};
    facet = {0, nullptr};
    move = {0, 0, 0};
    rotate = {0, 0, 0};
    modelScale = 1;

    colorWidget = QColor(Qt::black);
    colorLine = QColor(Qt::darkBlue);
    colorPoint = QColor(Qt::red);

    pointSize = 1;
    lineWidth = 1;


}



GLviewer::~GLviewer()
{
//    delete ui;
}

//setlocale(LC_ALL, C);

void GLviewer::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
/////////////////////////////
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);
//    vertex = {0, nullptr};
//    facet = {0, nullptr};

//    glEnable(GL_DEPTH_TEST);
//    glMatrixMode(GL_MODELVIEW);

}

void GLviewer::resizeGL(int w, int h)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
////    glOrtho(-1, 1, -1, 1, 1, 10);
//    glFrustum(-10, 10, -10, 10, -1, 10);
//     glFrustum(-1, 1, -1, 1, 1, 100);
     glFrustum(-1000, 1000, -1000, 1000, 1000, 1000);


}


void GLviewer::paintGL()
{
    glClearColor(colorWidget.redF(), colorWidget.greenF(), colorWidget.blueF(), 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glTranslatef(0, 0, 0);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);



    drawShape();
    update();

}


void GLviewer::drawShape()
{

        //Projection//
//        glDisable(GL_DEPTH_TEST);
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glFrustum(-1000, 1000, -1000, 1000, 1000, 1000);
//        glFrustum(-1, 1, -1, 1, 1, 100);


//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//        glOrtho(-100, 100, 800, 800, 100, 10);

//        update();

//        glTranslatef(x, y, z); //  перемещение по x y z
        glScaled(scale, scale, scale); // масштаб



    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_DOUBLE, 0, vertex.arg);

        //Poligons//
//        glPolygonMode(GL_FRONT, GL_TRIANGLES);
//        glPolygonMode(GL_BACK, GL_QUADS);

        // Points//
        glEnable(GL_POINT_SMOOTH);
//        glDisable(GL_POINT_SMOOTH);
        glPointSize(pointSize);
        glColor3d(colorPoint.redF(),colorPoint.greenF(),colorPoint.blueF());
        glDrawElements(GL_POINTS, facet.count, GL_UNSIGNED_INT, facet.arg);
        //Lines//
//        glLineStipple(4, 0x00FF);
//        glLineStipple(2, 255);
        glColor3d(colorLine.redF(),colorLine.greenF(),colorLine.blueF());
        glLineWidth(lineWidth);
        glDrawElements(GL_LINES, facet.count, GL_UNSIGNED_INT, facet.arg);


//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();

     glDisableClientState(GL_VERTEX_ARRAY);

//         std::cout<< "drawShape" << count++ <<std::endl;
}



void GLviewer::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
    update();
}

void GLviewer::mouseMoveEvent(QMouseEvent* mo)
{
//    xRot += 0.09/M_PI * (mo->pos().y() - mPos.y());
//    yRot += 0.09/M_PI * (mo->pos().x() - mPos.x());
//    update();

    if (!(mo->pos().x() >= 625 && mo->pos().x() <= 901 && mo->pos().y() >= 630 && mo->pos().y() <= 851)) {
        xRot += 1 / M_PI*(mo->pos().y()-mPos.y());
        yRot += 1 / M_PI*(mo->pos().x()-mPos.x());
    }


    mPos = mo->pos();

    update();
}

void GLviewer::change_zoom(double value) {
  scale *= value;
  update();
}


