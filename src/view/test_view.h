#ifndef INC_3DVIEWER_V2_0_SRC_VIEW_TEST_VIEW_H_
#define INC_3DVIEWER_V2_0_SRC_VIEW_TEST_VIEW_H_

#include "../model/facade.h"

namespace s21 {
class TestView : public Observer {
 public:
  void update(std::vector<double> &vertex) override;

 private:
};
}

#endif //INC_3DVIEWER_V2_0_SRC_VIEW_TEST_VIEW_H_
