//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
#include <cmath>
#include <vector>

#include "../../../view/type_transform.h"
#include "../../dao/data_model.h"

namespace s21 {

class TransformStrategy {
 public:
  virtual void transform(double offset, Axis axis) = 0;
  virtual ~TransformStrategy() {}
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
