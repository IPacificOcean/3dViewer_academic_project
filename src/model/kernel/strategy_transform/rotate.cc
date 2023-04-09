//
// Created by Violator Emilie on 3/27/23.
//

#include "rotate.h"

constexpr std::pair<int, int> GetIndexSpinningAxes(Axis axis) {
    if (axis == X) return {1, 2};
    if (axis == Y) return {0, 2};
    if (axis == Z) return {0, 1};
}

constexpr double RotateFirstAxis(double &offset, const double &first_axis, const double &second_axis) {
    return cos(CalculateRadians(offset)) * first_axis -
           sin(CalculateRadians(offset)) * second_axis;
}

constexpr double RotateSecondAxis(double &offset, const double &first_axis, const double &second_axis) {
    return sin(CalculateRadians(offset)) * first_axis +
           cos(CalculateRadians(offset)) * second_axis;
}

void s21::Rotate::transform(double offset, Axis axis) {
    std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
    setDifferenceOffset(offset, axis);
    std::pair<int, int> spinning_axes = GetIndexSpinningAxes(axis);
    for (unsigned int i = 3; i < vertex.size(); i += 3) {
        double first_axis = vertex[i + spinning_axes.first];
        double second_axis = vertex[i + spinning_axes.second];
        switch (axis) {
            case X:
                vertex[i + spinning_axes.first] =
                        RotateFirstAxis(offset_x_, first_axis, second_axis);
                vertex[i + spinning_axes.second] =
                        RotateSecondAxis(offset_x_, first_axis, second_axis);
                break;
            case Y:
                vertex[i + spinning_axes.first] =
                        RotateFirstAxis(offset_y_, first_axis, second_axis);
                vertex[i + spinning_axes.second] =
                        RotateSecondAxis(offset_y_, first_axis, second_axis);
                break;
            case Z:
                vertex[i + spinning_axes.first] =
                        RotateFirstAxis(offset_z_, first_axis, second_axis);
                vertex[i + spinning_axes.second] =
                        RotateSecondAxis(offset_z_, first_axis, second_axis);
                break;
        }
    }
    setDifferenceOffsetBack(offset, axis);
}
