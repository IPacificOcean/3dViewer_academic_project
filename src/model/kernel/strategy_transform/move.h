#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_

#include "tranform_strategy.h"

namespace s21 {
class Move : public TransformStrategy {
  void transform(double offset, Axis axis) override {
    std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
    setDifferenceOffset(offset, axis);
    for (unsigned int i = 3; i < vertex.size(); i += 3) {
      switch (axis) {
        case X:
          vertex[i] += this->offset_x;
          break;
        case Y:
          vertex[i + 1] += this->offset_y;
          break;
        case Z:
          vertex[i + 2] += this->offset_z;
          break;
      }
    }
    setDifferenceBack(offset, axis);
  }
};
}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_MOVE_H_
