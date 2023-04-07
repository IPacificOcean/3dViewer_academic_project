#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_

#include <iostream>

#include "tranform_strategy.h"

namespace s21 {
class Scale : public TransformStrategy {
  void transform(double scale, Axis axis = X) override {
    std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
    if (scale <= 0) {
      scale = 1;
    }
    SetDifferenceScale(scale);

    for (unsigned int i = 3; i < vertex.size(); i += 3) {
      vertex[i] *= this->scale_;
      vertex[i + 1] *= this->scale_;
      vertex[i + 2] *= this->scale_;
    }
    SetDifferenceScaleBack(scale);
  }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
