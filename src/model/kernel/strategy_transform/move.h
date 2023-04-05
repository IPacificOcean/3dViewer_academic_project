//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_

#include <iostream>

#include "tranform_strategy.h"

namespace s21 {
class Move : public TransformStrategy {
  void transform(double offset, Axis axis) override {
    std::vector<double> vertex =
        DataModel::GetInstance()
            ->GetVertex();  // TODO лучше использовать ссылку

    for (unsigned int i = 3; i < vertex.size(); i += 3) {
      switch (axis) {
        case X:
          vertex[i] += offset;
          break;
        case Y:
          vertex[i + 1] += offset;
          break;
        case Z:
          vertex[i + 2] += offset;
          break;
      }
    }

//    DataModel::GetInstance()->SetVertex(vertex);
    std::cout << "___MOVE___" << std::endl;
  }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
