#include "glviewer.h"
#include "ui_glviewer.h"
//#include <clocale.h>


GLviewer::GLviewer(QWidget *parent)
    : QOpenGLWidget(parent)
{
//    ui->setupUi(this);
    setWindowTitle("3Dviewer");
    setGeometry(400, 200, 1200, 900);
    vertex = {0, nullptr};
    facet = {0, nullptr};
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);
//    vertex = {0, nullptr};
//    facet = {0, nullptr};

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void GLviewer::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, 1, 10);
//    glFrustum(-1, 1, -1, 1, 1, 5);
}


void GLviewer::paintGL()
{
//    glClearColor(0, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, 0);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);



    drawShape();
}


void GLviewer::drawShape()
{

        //Projection//
        glDisable(GL_DEPTH_TEST);
//        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glFrustum(-1000, 1000, -1000, 1000, -1000, 1000);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glEnable(GL_DEPTH_TEST);
//        glOrtho(-1, 1, -1, 1, -100, 100);

        update();

//        glTranslatef(x, y, z); //  перемещение по x y z
        glScaled(scale, scale, scale); // масштаб



    glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3,GL_DOUBLE, 0, vertex.arg_v);

        //Poligons//
//        glPolygonMode(GL_FRONT, GL_TRIANGLES);
//        glPolygonMode(GL_BACK, GL_QUADS);

        // Points//
        glEnable(GL_POINT_SMOOTH);
        glPointSize(7);
        glColor3d(1,0,0);
        glDrawElements(GL_POINTS, facet.count, GL_UNSIGNED_INT, facet.arg_f);
        //Lines//
//        glLineStipple(4, 0x00FF);
//        glLineStipple(2, 255);
        glColor3d(0,0,1);
        glLineWidth(1);
        glDrawElements(GL_LINES, facet.count, GL_UNSIGNED_INT, facet.arg_f);


//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();

     glDisableClientState(GL_VERTEX_ARRAY);
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


