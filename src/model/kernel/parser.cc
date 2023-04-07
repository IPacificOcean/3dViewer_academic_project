//
// Created by Violator Emilie on 3/27/23.
//

#include "parser.h"

#include <ctime>
#include <sstream>

void print(std::ifstream &testfile) {
  std::string line;
  while (getline(testfile, line)) {
    std::cout << line << '\n';
  }
  testfile.seekg(0);
}

int count_number_in_string(size_t *count, std::string &line) {
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

  std::cout << "s21::Parser::OpenFile\n";  // !!!

  std::vector<double> &vertex = DataModel::GetInstance()->AccessVertex();
  std::vector<unsigned int> &facets = DataModel::GetInstance()->AccessFacets();
  vertex.clear();
  facets.clear();
  GetDataVetrtexAndFacet(input_file, vertex, facets);

  unsigned int end_time = clock();  // конечное время

  std::cout << "OpenFile TIME = " << end_time - start_time;  // искомое время
}

void s21::Parser::GetDataVetrtexAndFacet(std::string &input_file,
                                         std::vector<double> &vertex,
                                         std::vector<unsigned int> &facets) {
  std::ifstream s_file(input_file);
  if (!s_file.is_open()) {
    throw std::invalid_argument("GetDataVetrtexAndFacet: file open error");
  }

  //  vertex.reserve(30000000);
  //  facets.reserve(30000000);

  vertex.push_back(0);
  vertex.push_back(0);
  vertex.push_back(0);

  std::string line;
  int count{};

  while (getline(s_file, line)) {
    std::stringstream s_stream(line);
    std::string token;
    int f_temp{};

    // vertex c++
    if (line[0] == 'v' && line[1] == ' ') {
      while (getline(s_stream, token, ' ')) {
        if (token == "v") continue;
        vertex.push_back(std::stod(token));
      }
    }

    //     facets c++
    if (line[0] == 'f' && line[1] == ' ') {
      count = 0;
      while (getline(s_stream, token, ' ')) {
        if (token == "f") {
          ++count;
          continue;
        }
        if (count == 1) {
          f_temp = std::stoi(token);
          facets.push_back(f_temp);
          ++count;
        } else {
          facets.push_back(std::stoi(token));
          facets.push_back(std::stoi(token));
        }
      }
      facets.push_back(f_temp);
    }

  }  // end while
  s_file.close();
}
