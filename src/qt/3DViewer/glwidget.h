#ifndef GLWIDGET_H
#define GLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include "QtOpenGLWidgets/qopenglwidget.h"
#include <QColorDialog>

#include "mainwindow.h"

extern "C" {
#include "../../parser.h"
}


class GLWidget : public QOpenGLWidget {
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = nullptr);

    float xRot, yRot, zRot;
    QPoint mPos;
    float scale;


    double modelScale;
    Vertexes vertex;
    Facets facet;
    Move move;
    Rotate rotate;
//    Scale scale;


    QColor colorWidget;
    QColor colorLine;
    QColor colorPoint;

    Vertexes getVertex() {
        return vertex;
    }

    Facets getFacets() {
        return facet;
    }

    void setVertexes (Vertexes vertex){
        this->vertex = vertex;
    }

    void setFacets (Facets facet){
        this->facet = facet;
    }

    void drawCube(float a);
    void drawCubeLine();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;


    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:


};

#endif // GLWIDGET_H
