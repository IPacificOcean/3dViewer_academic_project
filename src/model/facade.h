//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_

#include "./dao/data_model.h"
#include "./kernel/parser.h"
#include "./kernel/strategy_transform/strategy_tranform.h"
#include "./observer/observable.h"


namespace s21 {

class Facade : public Observable {
 public:
  Facade() {}




  void ParseObj() {
    DataModel::GetInstance()->SetFacetsSize(123);
    this->notifyUpdate();
  }

  void OpenFile() {
    parser_.OpenFile();
    this->notifyUpdate();
  }

  void TransformObject();

 private:
  Parser parser_{};
//  StrategyTransform transform_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
