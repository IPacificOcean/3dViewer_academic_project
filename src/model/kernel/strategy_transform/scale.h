//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_

#include <iostream>

#include "tranform_strategy.h"

namespace s21 {
class Scale : public TransformStrategy {
  void transform(double scale, Axis axis = X) override {
    std::vector<double> vertex =
        DataModel::GetInstance()
            ->GetVertex();  // TODO лучше использовать ссылку

    for (unsigned int i = 3; i < vertex.size(); i += 3) {
      vertex[i] *= scale;
      vertex[i + 1] *= scale;
      vertex[i + 2] *= scale;
    }

//    DataModel::GetInstance()->SetVertex(vertex);
    std::cout << "___SCALE___" << std::endl;
  }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
