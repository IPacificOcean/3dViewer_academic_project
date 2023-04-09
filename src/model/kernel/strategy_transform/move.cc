//
// Created by Violator Emilie on 3/27/23.
//

#include "move.h"

void s21::Move::transform(double offset, Axis axis) {
        std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
        setDifferenceOffset(offset, axis);
        for (unsigned int i = 3; i < vertex.size(); i += 3) {
            switch (axis) {
                case X:
                    vertex[i] += this->offset_x_;
                    break;
                case Y:
                    vertex[i + 1] += this->offset_y_;
                    break;
                case Z:
                    vertex[i + 2] += this->offset_z_;
                    break;
            }
        }
        setDifferenceOffsetBack(offset, axis);
}
