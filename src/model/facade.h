//
// Created by Violator Emilie on 3/27/23.
//

#include <iostream>
#include <fstream>
#include <string>

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_

class Facade {

 public:

  void test() {

	std::string line;
	std::ifstream testfile("/Users/violator/github/3DViewer_v2.0/src/model/test.txt");
	if (testfile.is_open()) {
	  while (getline(testfile, line)) {
		std::cout << line << '\n';
	  }
	  testfile.close();
	} else std::cout << "Unable to open file";

  }

 private:

};

#endif //INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
