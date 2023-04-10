#include "glviewer.h"
#include <QDebug>
#include <memory>


GLviewer::GLviewer(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("3Dviewer");
//    setGeometry(400, 200, 1200, 900);
    modelScale = 1;
    scale = 0.05;

    colorWidget = QColor(Qt::lightGray);
    colorLine = QColor(Qt::darkBlue);
    colorPoint = QColor(Qt::red);

    pointSize = 4;
    lineWidth = 2;
    pointForm = POINT_ROUND;
    lineForm = LINE_SOLID;
    frustum = EMPTY;
}



GLviewer::~GLviewer()
{
    //    delete ui;
}

void GLviewer::initializeGL()
{
    glEnable(GL_DEPTH_TEST);

}

void GLviewer::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void GLviewer::paintGL(){
    // бесконечный цикл
    glClearColor(colorWidget.redF(), colorWidget.greenF(), colorWidget.blueF(), 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    projectionSelect();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -5);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
//    glRotatef(zRot, 0, 0, 1);

    drawShape();
    update();
//    qInfo() << "paintGL()";
}

void GLviewer::drawShape()
{
        glScaled(scale, scale, scale);
        glEnableClientState(GL_VERTEX_ARRAY);
//        glVertexPointer(3,GL_DOUBLE, 0, vertex.arg);
        glVertexPointer(3,GL_DOUBLE, 0, s21::DataModel::GetInstance()->GetVertex().data());

        // Points//
        if (pointForm != EMPTY){
            pointSettingForm();
        }
        //Lines//
        if (lineForm != EMPTY){
            lineSettingForm();
        }
        glDisableClientState(GL_VERTEX_ARRAY);
}

void GLviewer::pointSettingForm()
{
    if (pointForm == POINT_ROUND){
    glEnable(GL_POINT_SMOOTH);
    } else if (pointForm == POINT_QUADRO) {
    glDisable(GL_POINT_SMOOTH);
    }
    glPointSize(pointSize);
    glColor3d(colorPoint.redF(),colorPoint.greenF(),colorPoint.blueF());
//    glDrawElements(GL_POINTS, facet.count, GL_UNSIGNED_INT, facet.arg);
    glDrawElements(GL_POINTS, s21::DataModel::GetInstance()->GetFacets().size(), GL_UNSIGNED_INT, s21::DataModel::GetInstance()->GetFacets().data());
}

void GLviewer::lineSettingForm()
{
    if (lineForm == LINE_DASHED) {
        glEnable(GL_LINE_STIPPLE);
    glLineStipple(4, 0x00FF);
////        glLineStipple(2, 255);
////        glLineStipple(1, 0x1C47);
    }
    glColor3d(colorLine.redF(),colorLine.greenF(),colorLine.blueF());
    glLineWidth(lineWidth);
//    glDrawElements(GL_LINES, facet.count, GL_UNSIGNED_INT, facet.arg);
    glDrawElements(GL_LINES, s21::DataModel::GetInstance()->GetFacets().size(), GL_UNSIGNED_INT, s21::DataModel::GetInstance()->GetFacets().data());

    glDisable(GL_LINE_STIPPLE);
}

void GLviewer::projectionSelect() {
    if (frustum == EMPTY) {

        glOrtho(-1, 1, -1, 1, 1, 99999);

    } else {

        glFrustum(-1, 1, -1, 1, 1, 99999);

    }
}

void GLviewer::mousePressEvent(QMouseEvent* mo)
{
    mPos = mo->pos();
    update();
}

void GLviewer::mouseMoveEvent(QMouseEvent* mo)
{
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
