//
// Created by Violator Emilie on 3/27/23.
//

#include <gtest/gtest.h>

#include <filesystem>
#include <iostream>

#include "../model/facade.h"
#include "../view/test_view/test_view.h"

using std::cout;
using std::endl;
using namespace s21;

class ModelTest : public ::testing::Test {
 protected:
  void SetUp() override {}

  Facade facade_;
  TestView test_view_;
  Controller controller_;
};

TEST_F(ModelTest, test) { cout << "first try" << endl; }

TEST_F(ModelTest, testFacade) {
  std::vector<double> test = {1, 2, 3, 4, 5, 6};
  //  Facade facade_(test);
  //  TestView test_view;
  //  facade_.addObserver(&test_view);
  //
  //  facade_.test();
  //  facade_.changeColor();
  int *leaks = new int[3];
}

TEST_F(ModelTest, test_data_model) {
  DataModel* dm;
  DataModel* test = dm->GetInstance();
  test->SetFileName("setName");
  test->SetFacets({1234});
  test->SetVertex({1234});

  cout << test->GetVertex().at(0) << endl;
  cout << test->GetFacets().at(0) << endl;

  EXPECT_EQ("setName", test->GetFileName());
}

TEST_F(ModelTest, TestViewConnectFacade) {
  controller_.addObserver(&test_view_);

  facade_.addObserver(&test_view_);
  facade_.ParseObj();

  test_view_.SubscribeToChangeDataModel();
}

TEST_F(ModelTest, TestTransformStrategy) {
  test_view_.TransformObject(MOVE, 12);
  test_view_.TransformObject(SCALE, 11);
  test_view_.TransformObject(ROTATE, 2);
}

TEST_F(ModelTest, Parser_OpenFile_ECXEPTION_bab_file) {
  std::string input_file = "";
  EXPECT_ANY_THROW(test_view_.OpenFile(input_file););
}

TEST_F(ModelTest, ParserOpenFileTest) {
  std::string current_path(std::filesystem::current_path().generic_string());
  std::cout << "Текущая папка ======" << current_path << std::endl;
  std::string input_file = current_path + "/objFiles/cube.obj";
  test_view_.OpenFile(input_file);
}
