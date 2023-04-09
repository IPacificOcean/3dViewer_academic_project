//
// Created by Qyburn Bongo on 4/10/23.
//

#include "transform_strategy.h"

void s21::TransformStrategy::setDifferenceOffset(const double &offset, Axis axis) {
    switch (axis) {
        case X:
            this->offset_x_ = this->offset_x_ - offset;
            break;
        case Y:
            this->offset_y_ = this->offset_y_ - offset;
            break;
        case Z:
            this->offset_z_ = this->offset_z_ - offset;
            break;
    }
}

void s21::TransformStrategy::setDifferenceOffsetBack(const double &offset, Axis axis) {
    switch (axis) {
        case X:
            this->offset_x_ = offset;
            break;
        case Y:
            this->offset_y_ = offset;
            break;
        case Z:
            this->offset_z_ = offset;
            break;
    }
}
