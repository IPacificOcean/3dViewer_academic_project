//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_

#include <fstream>
#include <iostream>
#include <string>

#include "./dao/data_model.h"
#include "./kernel/parser.h"
#include "./observer/observable.h"
#include "./observer/observer.h"

namespace s21 {

class Facade : public Observable {
 public:
  Facade() {}
  void test() {
    std::string line;
    std::ifstream testfile(
        "/Users/violator/github/3DViewer_v2.0/src/model/test.txt");
    if (testfile.is_open()) {
      while (getline(testfile, line)) {
        std::cout << line << '\n';
      }
      testfile.close();
    } else {
      std::cout << "Unable to open file";
    }
  }
  //  void OpeningAndDrawing(std::string path) {}
  void Parse() {
    DataModel *data_model = DataModel::GetInstance();
    data_model->SetFacetsSize(123);
    this->notifyUpdate();
  }

 private:
  Parser parser_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
