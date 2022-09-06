#include "glviewer.h"
#include "ui_glviewer.h"
//#include <clocale.h>


GLviewer::GLviewer(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::GLviewer)
{
    ui->setupUi(this);
    setWindowTitle("3Dviewer");
    setGeometry(400, 200, 800, 600);

}



GLviewer::~GLviewer()
{
    delete ui;
}

//setlocale(LC_ALL, "en_US.UTF-8");

void GLviewer::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
/////////////////////////////
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0, 0.0, 0.0, 1.0);

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
//    glScalef(1.5, 1.5, 1.5);
//    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
//    drawCube(0.5);
    drawCubeLine();
}

void GLviewer::drawCube(float a)
{
    float ver_cub[] = {
        -a,-a,a, a,-a,a, a,a,a, -a,a,a,
        a,-a,-a, -a,-a,-a, -a,a,-a, a,a,-a,
        -a,-a,-a, -a,-a,a, -a,a,a, -a,a,-a,
        a,-a,a, a,-a,-a, a,a,-a, a,a,a,
        -a,-a,a, a,-a,a, a,-a,-a, -a,-a,-a,
        -a,a,a, a,a,a, a,a,-a, -a,a,-a
    };

    float color_arr[] = {
        1,0,0, 1,0,0, 1,0,0, 1,0,0,
        0,0,1, 0,0,1, 0,0,1, 0,0,1,
        1,1,0, 1,1,0, 1,1,0, 1,1,0,
        0,1,1, 0,1,1, 0,1,1, 0,1,1,
        1,0,1, 1,0,1, 1,0,1, 1,0,1,
        1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5, 1,0.5,0.5

    };

    glVertexPointer(3,GL_FLOAT, 0, &ver_cub);
    glEnableClientState(GL_VERTEX_ARRAY);

    glColorPointer(3,GL_FLOAT, 0, &color_arr);
    glEnableClientState(GL_COLOR_ARRAY);

        glDrawArrays(GL_QUADS, 0, 24);
//        glDrawElements(GL_LINES, 124, GL_UNSIGNED_INT, &ver_cub);

     glDisableClientState(GL_COLOR_ARRAY);
     glDisableClientState(GL_VERTEX_ARRAY);
}

void GLviewer::drawCubeLine()
{
    Vertexes vertex = {0, nullptr};
    Facets facet = {0, nullptr};
    QString file = "/Users/qyburnbo/Desktop/Projects/C8_3DViewer_v1.0-1/src/source/lamp.obj";
    QByteArray ba = file.toLocal8Bit();
    char *str = ba.data();
    parser(str , &vertex, &facet);
//    for (unsigned int a = 1; a < facet.count; a++) {
//        std::cout << facet.arg_f[a] << "\t";
//        if (a % 3 == 0) {
//           std::cout << std::endl;
//        }
//    }
//    std::cout << std::endl;


//    unsigned int index_v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // можно перенести в paint?
//    glMatrixMode(GL_MODELVIEW);/// можно перенести в paint?
//    glLoadIdentity();///можно перенести в paint?



    float ver_cub[] = {
////        0.0, 0.0, 0.0,
////        0.0, 0.0, 0.5,
////        0.0, 0.5, 0.0,
////        0.0, 0.5, 0.5,
////        0.5, 0.0, 0.0,
////        0.5, 0.0, 0.5,
////        0.5, 0.5, 0.0,
////        0.5, 0.5, 0.5
//        1.000000, -1.000000, -1.000000,
//       1.000000, -1.000000, 1.000000,
//       -1.000000, -1.000000, 1.000000,
//       -1.000000, -1.000000, -1.000000,
//       1.000000, 1.000000, -0.999999,
//       0.999999, 1.000000, 1.000001,
//       -1.000000, 1.000000, 1.000000,
//       -1.000000, 1.000000, -1.000000
         0, 0, 0,
         0, 0, 2,
         0, 2, 0,
         0, 2, 2,
         2, 0, 0,
         2, 0, 2,
         2, 2, 0,
         2, 2, 2
    };



    unsigned int index_arr[] = {
//        0, 6, 6, 4, 4, 0,
//        0, 2, 2, 6, 6, 0,
//        0, 3, 3, 2, 2, 0,
//        0, 1, 1, 3, 3, 0,
//        2, 7, 7, 6, 6, 2,
//        2, 3, 3, 7, 7, 2,
//        4, 6, 6, 7, 7, 4,
//        4, 7, 7, 5, 5, 4,
//        0, 4, 4, 5, 5, 0,
//        0, 5, 5, 1, 1, 0
//         1, 2, 3,
//         7, 6, 5,
//         4, 5, 1,
//         5, 6, 2,
//         2, 6, 7,
//         0, 3, 7,
//         0, 1, 3,
//         4, 7, 5,
//         0, 4, 1,
//         1, 5, 2,
//         3, 2, 7,
//         4, 0, 7

//        1, 7, 5,
//        1, 3, 7,
//        1, 4, 3,
//        1, 2, 4,
//        3, 8, 7,
//        3, 4, 8,
//        5, 7, 8,
//        5, 8, 6,
//        1, 5, 6,
//        1, 6, 2
        1,	7,	7,	5,	5,	1,
        1,	3,	3,	7,	7,	1,
        1,	4,	4,	3,	3,	1,
        1,	2,	2,	4,	4,	3,
        3,	8,	8,	7,	7,	3,
        3,	4,	4,	8,	8,	5,
        5,	7,	7,	8,	8,	5,
        5,	8,	8,	6,	6,	1,
        1,	5,	5,	6,	6,	1,
        1,	6,	6,	2,	2,	1
    };






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

void GLviewer::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
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


