//
// Created by Violator Emilie on 3/27/23.
//


#include "../model/facade.h"

#ifndef INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
#define INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_


namespace s21 {

class Controller {
 public:

  void addObserver(Observer *observer) {
    facade_.addObserver(observer);
  }

  void ParseObj() {
    facade_.ParseObj();
  }

  void OpenFile();
  void SaveSettings();
  void TransformObject() {
    facade_.TransformObject();
  }
  void SetProjection();
  void Customize();
  void SavePng();
  void SaveGif();

 private:
  Facade facade_{};

};

}



#endif //INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
