//
// Created by Violator Emilie on 3/27/23.
//

#include "scale.h"

void s21::Scale::transform(double scale, Axis axis) {
    std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
    if (scale <= 0) {
        scale = 1;
    }
    SetDifferenceScale(scale);

    for (unsigned int i = 3; i < vertex.size(); i += 3) {
        vertex[i] *= this->scale_;
        vertex[i + 1] *= this->scale_;
        vertex[i + 2] *= this->scale_;
    }
    SetDifferenceScaleBack(scale);
}
