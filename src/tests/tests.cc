//
// Created by Violator Emilie on 3/27/23.
//

#include <gtest/gtest.h>

#include <iostream>
#include "../model/facade.h"


using std::cout;
using std::endl;

class ModelTest : public ::testing::Test {
 protected:
  void SetUp() override {}
  Facade facade_;

};

TEST_F(ModelTest, test) {

cout << "first try" << endl;


}

TEST_F(ModelTest, testFacade) {

  facade_.test();


}
