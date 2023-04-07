#ifndef INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
#define INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/facade.h"
#include "../view/type_transform.h"

namespace s21 {

class Controller {
 public:
  void addObserver(Observer* observer) { facade_.addObserver(observer); }

  void OpenFile(std::string& input_file) { facade_.OpenFile(input_file); }
  void TransformObject(TypeTransform type_transform, double offset, Axis axis) {
    facade_.TransformObject(type_transform, offset, axis);
  }

  double GetOptimizeScale() { return facade_.GetOptimizeScale(); }

  void SetProjection();
  void Customize();
  void SavePng();
  void SaveGif();

 private:
  Facade facade_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_CONTROLLER_CONTROLLER_H_
