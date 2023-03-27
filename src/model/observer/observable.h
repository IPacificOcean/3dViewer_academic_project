//
// Created by Tysane Norine on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_OBSERVER_OBSERVABLE_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_OBSERVER_OBSERVABLE_H_

#include "observer.h"
#include <vector>

class Observable {
 public:
  void addObserver(Observer *observer) {
	observers_.push_back(observer);
  }
  void notifyUpdate(std::vector<double> &vertex) {
	int size = observers_.size();
	for (int i = 0; i < size; i++) {
	  observers_[i]->update(vertex);
	}
  }
 private:
  std::vector<Observer *> observers_;
};

#endif //INC_3DVIEWER_V2_0_SRC_MODEL_OBSERVER_OBSERVABLE_H_
