//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_

namespace s21 {

class TransformStrategy {
 public:
  virtual void transform() = 0;
  virtual ~TransformStrategy() {}
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
