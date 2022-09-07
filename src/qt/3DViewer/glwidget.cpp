#include "glwidget.h"
#include "GLUT/glut.h"


GLWidget ::  GLWidget(QWidget *parent) : QOpenGLWidget (parent) {


}


void GLWidget::initializeGL() {


    glEnable(GL_DEPTH_TEST);
/////////////////////////////
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);

//    glClearColor(0.51,0.68, 0.72, 0);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::resizeGL(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


//    glViewport(0,0, w,h);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluPerspective(45.0, (float) w/h, 0.01, 100.0);

//    updateGL();

}

void GLWidget::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    glScalef(1.5, 1.5, 1.5);
//    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
//    drawCube(0.5);
    drawCubeLine();



//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();

//    glColor3f(1,0,0);
//    glutSolidSphere(0.5 ,100,100);

}


void GLWidget::drawCubeLine() {


//    Vertexes vertex = {0, nullptr};
//    Facets facet = {0, nullptr};
//    QString file = "/Users/violator/C8_3DViewer_v1.0-1/src/lamp.obj";
//    QByteArray ba = file.toLocal8Bit();
//    char *str = ba.data();
//    parser(str , &vertex, &facet);


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // можно перенести в paint?

    //        glDrawArrays(GL_QUADS, 0, 24);

            //Poligons//
    //        glPolygonMode(GL_FRONT, GL_LINE);
    //        glPolygonMode(GL_BACK, GL_LINE);
    //        glDrawElements(GL_POLYGON, facet.count, GL_UNSIGNED_INT, facet.arg_f);
            // Points//
            glEnable(GL_POINT_SMOOTH);
            glPointSize(7);
            glColor3d(1,0,0);
            //Projection//
            glDisable(GL_DEPTH_TEST);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glFrustum(-100, 100, -100, 100, -100, 100);
    //        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //        glEnable(GL_DEPTH_TEST);
    //        glOrtho(-1, 1, -1, 1, -100, 100);

            update();

    //        glTranslatef(x, y, z); //  перемещение по x y z

            glVertexPointer(3,GL_DOUBLE, 0, vertex.arg_v);
            glEnableClientState(GL_VERTEX_ARRAY);

            glScaled(0.1, 0.1, 0.1); // масштаб
    //        glDrawElements(GL_LINE_LOOP, facet.count, GL_UNSIGNED_INT, facet.arg_f);
    //        glDrawElements(GL_POINTS, facet.count, GL_UNSIGNED_INT, facet.arg_f);
            //Lines//
    //        glLineStipple(4, 0x00FF);
    //        glLineStipple(2, 255);
            glColor3d(0,0,1);
            glLineWidth(1);
            glDrawElements(GL_LINES, facet.count, GL_UNSIGNED_INT, facet.arg_f);


            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();





            glDisableClientState(GL_VERTEX_ARRAY);
}


void GLWidget::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent* mo)
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






















