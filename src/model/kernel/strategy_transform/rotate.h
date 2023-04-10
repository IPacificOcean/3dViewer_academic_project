#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_

#include "transform_strategy.h"

namespace s21 {
constexpr double CalculateRadians(double& offset) {
  return offset * M_PI / 180;
}

constexpr std::pair<int, int> GetIndexSpinningAxes(Axis axis);

constexpr double RotateFirstAxis(double& offset, const double& first_axis,
                                 const double& second_axis);

constexpr double RotateSecondAxis(double& offset, const double& first_axis,
                                  const double& second_axis);

class Rotate : public TransformStrategy {
  void transform(double offset, Axis axis) override;
};
}  // namespace s21
#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
