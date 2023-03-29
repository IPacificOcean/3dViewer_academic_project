//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_

#include "tranform_strategy.h"
#include <iostream>

namespace s21 {
class Rotate : public TransformStrategy {
  void transform() override {
    std::cout << "___ROTATE___" << std::endl;
  }
};
}  // namespace s21
#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
