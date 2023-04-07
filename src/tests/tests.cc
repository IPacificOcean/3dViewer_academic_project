//
// Created by Violator Emilie on 3/27/23.
//

#include <gtest/gtest.h>

#include <filesystem>
#include <iostream>
#include <memory>

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
}

TEST_F(ModelTest, TestViewConnectFacade) {
  controller_.addObserver(&test_view_);

  facade_.addObserver(&test_view_);
//  facade_.ParseObj();

  test_view_.SubscribeToChangeDataModel();
}

TEST_F(ModelTest, TestTransformStrategy) {
  test_view_.TransformObject(MOVE, 12);
  test_view_.TransformObject(SCALE, 11);
  test_view_.TransformObject(ROTATE, 2);
}

TEST_F(ModelTest, Parser_OpenFile_ECXEPTION_bab_file) {
    std::string input_file = "";
//    EXPECT_ANY_THROW(test_view_.OpenFile(input_file););
}

TEST_F(ModelTest, ParserOpenFileTest) {
   std::string current_path(std::filesystem::current_path().generic_string());
   std::cout << "Текущая папка ======" << current_path << std::endl;
   std::string input_file = current_path + "/objFiles/cube.obj";
   test_view_.OpenFile(input_file);
 }

 TEST_F(ModelTest,  LeaksTestDragon) {
   std::string current_path(std::filesystem::current_path().generic_string());
   std::cout << "Текущая папка ======" << current_path << std::endl;
   std::string input_file = current_path + "/objFiles/Dragon.obj";
   test_view_.OpenFile(input_file);
 }

 TEST_F(ModelTest,  LeaksTestHeli) {
   std::string current_path(std::filesystem::current_path().generic_string());
   std::cout << "Текущая папка ======" << current_path << std::endl;
   std::string input_file = current_path + "/objFiles/Heli.obj";
   test_view_.OpenFile(input_file);
 }

 TEST_F(ModelTest,  LeaksTestCat) {
   std::string current_path(std::filesystem::current_path().generic_string());
   std::cout << "Текущая папка ======" << current_path << std::endl;
   std::string input_file = current_path + "/objFiles/cat.obj";
   test_view_.OpenFile(input_file);
 }

//  TODO tests affine transform
// TEST_F(ModelTest, ParserOpenFileTest_violator) {
//   std::string input_file =
//       "/Users/violator/CPP4_3DViewer_v2.0-1/src/objFiles/cube.obj";
//   test_view_.OpenFile(input_file);
// }
//
// TEST_F(ModelTest, ParserVertexesCount) {
//   std::string input_file =
//       "/Users/violator/CPP4_3DViewer_v2.0-1/src/objFiles/cube.obj";
//   test_view_.OpenFile(input_file);
//   EXPECT_EQ(DataModel::GetInstance()->GetVertexSize(), 27);
// }
//
// TEST_F(ModelTest, ParserFacetsCount) {
//   std::string input_file =
//       "/Users/violator/CPP4_3DViewer_v2.0-1/src/objFiles/cube.obj";
//   test_view_.OpenFile(input_file);
//   EXPECT_EQ(DataModel::GetInstance()->GetFacetsSize(), 60);
// }


// facet old  [0] 1 [1] 2 [2] 2 [3] 3 [4] 3 [5] 1 [6] 1 [7] 4 [8] 4 [9] 2 [10] 2 [11] 1 [12] 1 [13] 5 [14] 5 [15] 4 [16] 4 [17] 1 [18] 1 [19] 6 [20] 6 [21] 5 [22] 5 [23] 1 [24] 4 [25] 7 [26] 7 [27] 2 [28] 2 [29] 4 [30] 4 [31] 5 [32] 5 [33] 7 [34] 7 [35] 4 [36] 3 [37] 2 [38] 2 [39] 7 [40] 7 [41] 3 [42] 3 [43] 7 [44] 7 [45] 8 [46] 8 [47] 3 [48] 1 [49] 3 [50] 3 [51] 8 [52] 8 [53] 1 [54] 1 [55] 8 [56] 8 [57] 6 [58] 6 [59] 1
// vertex old [0] 0 [1] 0 [2] 0 [3] 0 [4] 0 [5] 0 [6] 2 [7] 2 [8] 0 [9] 2 [10] 0 [11] 0 [12] 0 [13] 2 [14] 0 [15] 0 [16] 2 [17] 2 [18] 0 [19] 0 [20] 2 [21] 2 [22] 2 [23] 2 [24] 2 [25] 0 [26] 2
// vertex old = 27
// facet old = 60

// facet new    [0] 1 [1] 2 [2] 2 [3] 3 [4] 3 [5] 1 [6] 1 [7] 4 [8] 4 [9] 2 [10] 2 [11] 1 [12] 1 [13] 5 [14] 5 [15] 4 [16] 4 [17] 1 [18] 1 [19] 6 [20] 6 [21] 5 [22] 5 [23] 1 [24] 4 [25] 7 [26] 7 [27] 2 [28] 2 [29] 4 [30] 4 [31] 5 [32] 5 [33] 7 [34] 7 [35] 4 [36] 3 [37] 2 [38] 2 [39] 7 [40] 7 [41] 3 [42] 3 [43] 7 [44] 7 [45] 8 [46] 8 [47] 3 [48] 1 [49] 3 [50] 3 [51] 8 [52] 8 [53] 1 [54] 1 [55] 8 [56] 8 [57] 6 [58] 6 [59] 1
// vertex new [0] 0 [1] 0 [2] 0 [3] 0 [4] 0 [5] 0 [6] 2 [7] 2 [8] 0 [9] 2 [10] 0 [11] 0 [12] 0 [13] 2 [14] 0 [15] 0 [16] 2 [17] 2 [18] 0 [19] 0 [20] 2 [21] 2 [22] 2 [23] 2 [24] 2 [25] 0 [26] 2
// vertex new = 27
// facet new = 60
//OpenFile new TIME = 27 736 455
//                    26 286 778
 // через терминал     5 174 337
 // терминал б.резерв  5 444 326
 // терминал c.резерв  5 178 973
//                     2 981 385

