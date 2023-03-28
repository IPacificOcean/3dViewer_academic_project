//
// Created by Violator Emilie on 3/27/23.
//

#include "test_view.h"
void s21::TestView::update() {
  std::cout << "\n____ОТРИСОВКА____\n" << std::endl;
  DataModel* data_model = DataModel::GetInstance();
  std::cout << "_____Кол-фасетов = " << data_model->GetFacetsSize() << std::endl;
  std::cout << std::endl;
}
