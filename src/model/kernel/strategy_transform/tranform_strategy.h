#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
#include <cmath>
#include <vector>

#include "../../../view/type_transform.h"
#include "../../dao/data_model.h"

namespace s21 {

class TransformStrategy {
 public:
  virtual ~TransformStrategy() {}
  virtual void transform(double offset, Axis axis) = 0;
  void setDifferenceOffset(const double& offset, Axis axis) { // нужно чтобы не было резких перепадов
    switch (axis) {
      case X:
        this->offset_x = this->offset_x - offset;
        break;
      case Y:
        this->offset_y = this->offset_y - offset;
        break;
      case Z:
        this->offset_z = this->offset_z - offset;
        break;
    }
  }
  void setDifferenceBack(const double& offset, Axis axis) { // нужно обратно вернуть значения
    switch (axis) {
      case X:
        this->offset_x = offset;
        break;
      case Y:
        this->offset_y = offset;
        break;
      case Z:
        this->offset_z = offset;
        break;
    }
  }

 protected:
  double offset_x{};
  double offset_y{};
  double offset_z{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_TRANFORM_STRATEGY_H_
