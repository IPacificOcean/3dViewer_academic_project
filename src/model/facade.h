#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_

//#include "../view/type_transform.h"
//#include "./dao/data_model.h"
#include "./kernel/parser.h"
#include "./kernel/strategy_transform/move.h"
#include "./kernel/strategy_transform/rotate.h"
#include "./kernel/strategy_transform/scale.h"
#include "./kernel/strategy_transform/tranform_strategy.h"
#include "./observer/observable.h"
#include "kernel/strategy_transform/transformer.h"

namespace s21 {

class Facade : public Observable {
 public:
  Facade() {
    transformer_move_ = new Transformer(new Move());
    transformer_rotate_ = new Transformer(new Rotate());
    transformer_scale_ = new Transformer(new Scale());
  }

  ~Facade() {
    delete transformer_move_;
    delete transformer_rotate_;
    delete transformer_scale_;
  }

  void OpenFile(std::string& input_file) {
    parser_.OpenFile(input_file);
    //    this->notifyUpdate();
  }

  void TransformObject(TypeTransform type_transform, double offset, Axis axis) {
    switch (type_transform) {
      case MOVE:
        transformer_move_->TransformObject(offset, axis);
        break;
      case ROTATE:
        transformer_rotate_->TransformObject(offset, axis);
        break;
      case SCALE:
        transformer_scale_->TransformObject(offset, axis);
        break;
    }
    this->notifyUpdate();
  }

 private:
  Parser parser_{};
  Transformer* transformer_move_;
  Transformer* transformer_rotate_;
  Transformer* transformer_scale_;
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_FACADE_H_
