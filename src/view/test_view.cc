//
// Created by Violator Emilie on 3/27/23.
//

#include "test_view.h"
void s21::TestView::update(std::vector<double> &vertex) {
  std::cout << "\n____changed____\n" << std::endl;
  for (auto& i : vertex) {
	std::cout << i << " ";
  }
  std::cout << std::endl;
}
