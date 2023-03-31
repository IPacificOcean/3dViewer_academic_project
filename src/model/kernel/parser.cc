//
// Created by Violator Emilie on 3/27/23.
//

#include "parser.h"

#include <ctime>

void print(std::ifstream &testfile) {
  std::string line;
  while (getline(testfile, line)) {
    std::cout << line << '\n';
  }
  testfile.seekg(0);
}

int count_number_in_string(unsigned int *count, std::string &line) {
  int temp_count = 0;
  const char *tmp = line.c_str();
  while (*tmp) {
    if (*tmp == ' ' && isdigit(*(tmp + 1))) {
      temp_count++;
    }
    tmp++;
  }
  *count += temp_count;
  return 1;
}

void s21::Parser::OpenFile(std::string &input_file) {
  unsigned int start_time = clock();  // начальное время

  std::cout << "s21::Parser::OpenFile\n";

  std::pair<unsigned int, int> pair{};

  try {
    //    print(testfile); // del

    pair = PreParser(input_file);

    std::cout << "vertexes_count = " << pair.first << '\n';
    std::cout << "facets_count = " << pair.second << '\n';

    GetDataVetrtexAndFacet(input_file);

  } catch (...) {
    throw;
  }

  std::vector<double> vertexes;
  std::vector<size_t> facets;
  //    ----WRITE DATA----
  DataModel::GetInstance()->SetFacetsSize(pair.first);
  DataModel::GetInstance()->SetVertexSize(pair.second);
  //  WriteData();
  //    ----WRITE DATA----
  unsigned int end_time = clock();  // конечное время

  std::cout << "OpenFile TIME = " << end_time - start_time;  // искомое время
}

std::pair<unsigned int, int> s21::Parser::PreParser(std::string &input_file) {
  std::ifstream file(input_file);
  if (!file.is_open()) {
    throw std::invalid_argument("file open error");
  }

  std::pair<unsigned int, int> pair;
  unsigned int vertexes_count{};
  unsigned int space_count{};
  std::string line{};

  // первый проход с подсчетом строк v f
  while (getline(file, line)) {
    //    std::cout << line << '\n';
    if (line[0] == 'v' && line[1] == ' ') {
      //      std::cout << "vertexes_count" << vertexes_count << '\n';
      ++vertexes_count;
    }

    if (line[0] == 'f' && line[1] == ' ') {
      count_number_in_string(&space_count, line);
    }
  }

  vertexes_count = vertexes_count * 3 + 3;
  space_count = space_count * 2;

  pair.first = vertexes_count;
  pair.second = space_count;

  file.close();

  return pair;
}

void s21::Parser::GetDataVetrtexAndFacet(std::string &input_file) {}

void s21::Parser::WriteData() { DataModel::GetInstance()->SetFacetsSize(123); }
