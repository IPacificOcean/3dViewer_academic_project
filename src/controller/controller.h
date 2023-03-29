//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
#define INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/facade.h"
#include "../view/type_transform.h"

namespace s21 {

class Controller {
 public:
  void addObserver(Observer *observer) { facade_.addObserver(observer); }

  void ParseObj() { facade_.ParseObj(); }

  void OpenFile();
  void SaveSettings();
  void TransformObject(TypeTransform type_transform) {
    facade_.TransformObject(type_transform);
  }
  void SetProjection();
  void Customize();
  void SavePng();
  void SaveGif();

 private:
  Facade facade_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
