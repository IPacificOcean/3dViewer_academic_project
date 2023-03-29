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

void s21::TestView::OpenFile() { controller_.OpenFile(); }

void s21::TestView::TransformObject(TypeTransform type_transform) {
  controller_.TransformObject(type_transform);
}
