//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_

#include "tranform_strategy.h"
#include <iostream>

namespace s21 {
class Scale : public TransformStrategy {
  void transform() override {
    std::cout << "___SCALE___" << std::endl;
  }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_SCALE_H_
