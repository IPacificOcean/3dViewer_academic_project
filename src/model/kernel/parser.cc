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

  std::pair<size_t, size_t> pair{};

  try {
    //    print(testfile); // del

    pair = PreParser(input_file);

    std::cout << "vertexes_count = " << pair.first << '\n';
    std::cout << "facets_count = " << pair.second << '\n';

    GetDataVetrtexAndFacet(input_file, pair.first, pair.second);

  } catch (...) {
    throw;
  }

  std::vector<double> vertexes;
  std::vector<size_t> facets;
  //    ----WRITE DATA----
  DataModel::GetInstance()->SetVertexSize(pair.first);
  DataModel::GetInstance()->SetFacetsSize(pair.second);
  //  WriteData();
  //    ----WRITE DATA----
  unsigned int end_time = clock();  // конечное время

  std::cout << "OpenFile TIME = " << end_time - start_time;  // искомое время
}

std::pair<size_t, size_t> s21::Parser::PreParser(std::string &input_file) {
  std::ifstream file(input_file);
  if (!file.is_open()) {
    throw std::invalid_argument("PreParser: file open error");
  }

  std::pair<size_t, size_t> pair;
  size_t vertexes_count{};
  size_t space_count{};
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

void s21::Parser::GetDataVetrtexAndFacet(std::string &input_file, size_t v_size,
                                         size_t f_size) {

  std::ifstream file(input_file);
  if (!file.is_open()) {
    throw std::invalid_argument("GetDataVetrtexAndFacet: file open error");
  }

  std::vector<double> vertexes;
  std::vector<size_t> facets;
  vertexes.reserve(v_size);
  facets.reserve(f_size);

  vertexes.push_back(0);
  vertexes.push_back(0);
  vertexes.push_back(0);
  facets.push_back(0);

  std::string line;
  while (getline(file, line)) {
    std::stringstream s_stream(line);
    std::string intermediate;

    // vertex c++
    if (line[0] == 'v' && line[1] == ' ') {
      while (getline(s_stream, intermediate, ' ')) {
        if (intermediate == "v") continue;
        vertexes.push_back(std::stod(intermediate));
      }
    }

    // facets c++
    if (line[0] == 'f' && line[1] == ' ') {

    }

  }


  if (vertexes.size() != v_size) {
    throw std::invalid_argument(
        "GetDataVetrtexAndFacet: vertexes.size() != v_size");
  }


  // facets
  //      if (temp_string[0] == 'f' && temp_string[1] == ' ') {
  //        numberOfTokens = 1;
  //        countTokes = 0;
  //        count_number_in_string(&numberOfTokens, temp_string);
  //        token = strtok(temp_string, seps);
  //        countTokes++;
  //
  //        while (token != NULL) {
  //          token = strtok(NULL, seps);
  //          countTokes++;
  //          if (countTokes == 2) {
  //            memset(temp, 0, 32);
  //            strcpy(temp, token);
  //          }
  //          if (token == NULL || *token == '\n') break;
  //          if (countTokes == 2) {
  //            facets->arg[arg_f_index] = atoi(token);
  //            arg_f_index++;
  //          } else {
  //            facets->arg[arg_f_index] = atoi(token);
  //            arg_f_index++;
  //            facets->arg[arg_f_index] = atoi(token);
  //            arg_f_index++;
  //          }
  //          if (numberOfTokens == countTokes) {
  //            facets->arg[arg_f_index] = atoi(temp);
  //            arg_f_index++;
  //          }
  //        }
  //      }
  //    }
  //  }

  //  return error;
}

void s21::Parser::WriteData() { DataModel::GetInstance()->SetFacetsSize(123); }
