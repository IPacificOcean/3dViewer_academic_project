//
// Created by Violator Emilie on 3/27/23.
//

#include <gtest/gtest.h>

#include <iostream>
#include "../model/facade.h"
#include "../view/test_view.h"

using std::cout;
using std::endl;
using namespace s21;

class ModelTest : public ::testing::Test {
 protected:
  void SetUp() override {}

};

TEST_F(ModelTest, test) {
  cout << "first try" << endl;
}

TEST_F(ModelTest, testFacade) {
  std::vector<double> test = {1, 2, 3, 4, 5, 6};
  Facade facade_(test);
  TestView test_view;
  facade_.addObserver(&test_view);

  facade_.test();
  facade_.changeColor();

}
