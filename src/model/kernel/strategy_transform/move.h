//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_

#include <iostream>

#include "tranform_strategy.h"

namespace s21 {
class Move : public TransformStrategy {
  void transform() override { std::cout << "___MOVE___" << std::endl; }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
