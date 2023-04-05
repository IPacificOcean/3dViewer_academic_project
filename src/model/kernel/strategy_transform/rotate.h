//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_

#include <iostream>

#include "tranform_strategy.h"

namespace s21 {
class Rotate : public TransformStrategy {
  void transform(double angle, Axis axis) override {
    std::vector<double> vertex =
        DataModel::GetInstance()
            ->GetVertex();  // TODO лучше использовать ссылку

    angle = angle * M_PI / 180;  // перевод в радианы

    int a = 0;
    int b = 0;
    switch (axis) { // определим вокруг какой оси будем круть
      case X:
        a = 1;
        b = 2;
        break;

      case Y:
        a = 0;
        b = 2;
        break;

      case Z:
        a = 0;
        b = 1;
        break;
    }

    for (size_t i = 3; i < vertex.size(); i += 3) {
      double a1 = vertex[i + a];
      double a2 = vertex[i + b];
      vertex[i + a] = cos(angle) * a1 - sin(angle) * a2;
      vertex[i + b] = sin(angle) * a1 + cos(angle) * a2;
    }

//    DataModel::GetInstance()->SetVertex(vertex);

    std::cout << "___ROTATE___" << std::endl;
  }
};
}  // namespace s21
#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
