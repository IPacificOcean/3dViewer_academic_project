//
// Created by Violator Emilie on 3/27/23.
//

#include "parser.h"

void s21::Parser::OpenFile() {

  std::string line;
  std::ifstream testfile(
      "/Users/violator/github/3DViewer_v2.0/src/model/kernel/parser.h");
  if (testfile.is_open()) {
    while (getline(testfile, line)) {
      std::cout << line << '\n';
    }
    testfile.close();
  } else {
    std::cout << "Unable to open file";
  }

}