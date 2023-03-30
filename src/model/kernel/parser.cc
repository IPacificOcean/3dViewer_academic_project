//
// Created by Violator Emilie on 3/27/23.
//

#include "parser.h"

void s21::Parser::OpenFile(std::string &input_file) {
  std::string line;

  std::ifstream testfile(input_file);

  if (testfile.is_open()) {
    while (getline(testfile, line)) {
      std::cout << line << '\n';
    }
    testfile.close();
  } else {
    std::cout << "Unable to open file";
  }

  WriteData();
}

void s21::Parser::WriteData() { DataModel::GetInstance()->SetFacetsSize(123); }
