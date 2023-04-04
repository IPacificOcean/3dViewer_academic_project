//
// Created by Violator Emilie on 3/27/23.
//

#include "test_view.h"

void s21::TestView::update() {
  std::cout << "\n____ОТРИСОВКА____\n" << std::endl;
  std::cout << "_____Кол-фасетов = "
            << DataModel::GetInstance()->GetFacetsSize() << std::endl;
  std::cout << std::endl;
  
}

void s21::TestView::OpenFile(std::string &input_file) {
  controller_.OpenFile(input_file);
}

void s21::TestView::TransformObject(TypeTransform type_transform, double offset, Axis axis) {
  controller_.TransformObject(type_transform, offset, axis);
}
