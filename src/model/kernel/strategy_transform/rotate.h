#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_

#include "tranform_strategy.h"

constexpr double CalculateRadians(double& offset) {
  return offset * M_PI / 180;
}

constexpr std::pair<int, int> GetIndexSpinningAxes(Axis axis) {
  if (axis == X) return {1, 2};
  if (axis == Y) return {0, 2};
  if (axis == Z) return {0, 1};
}

constexpr double RotateFirstAxis(double& offset, const double& first_axis,
                                 const double& second_axis) {
  return cos(CalculateRadians(offset)) * first_axis -
         sin(CalculateRadians(offset)) * second_axis;
}

constexpr double RotateSecondAxis(double& offset, const double& first_axis,
                                  const double& second_axis) {
  return sin(CalculateRadians(offset)) * first_axis +
         cos(CalculateRadians(offset)) * second_axis;
}

namespace s21 {
class Rotate : public TransformStrategy {
  void transform(double offset, Axis axis) override {
    std::vector<double>& vertex = DataModel::GetInstance()->AccessVertex();
    setDifferenceOffset(offset, axis);
    std::pair<int, int> spinning_axes = GetIndexSpinningAxes(axis);
    for (unsigned int i = 3; i < vertex.size(); i += 3) {
      double first_axis = vertex[i + spinning_axes.first];
      double second_axis = vertex[i + spinning_axes.second];
      switch (axis) {
        case X:
          vertex[i + spinning_axes.first] =
              RotateFirstAxis(offset_x, first_axis, second_axis);
          vertex[i + spinning_axes.second] =
              RotateSecondAxis(offset_x, first_axis, second_axis);
          break;
        case Y:
          vertex[i + spinning_axes.first] =
              RotateFirstAxis(offset_y, first_axis, second_axis);
          vertex[i + spinning_axes.second] =
              RotateSecondAxis(offset_y, first_axis, second_axis);
          break;
        case Z:
          vertex[i + spinning_axes.first] =
              RotateFirstAxis(offset_z, first_axis, second_axis);
          vertex[i + spinning_axes.second] =
              RotateSecondAxis(offset_z, first_axis, second_axis);
          break;
      }
    }
    setDifferenceBack(offset, axis);
  }
};
}  // namespace s21
#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_KERNEL_STRATEGY_TRANSFORM_ROTATE_H_
