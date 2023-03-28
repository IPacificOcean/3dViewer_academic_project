//
// Created by Violator Emilie on 3/27/23.
//

#include "data_model.h"

s21::DataModel* s21::DataModel::GetInstance() {
  if (!instance_) {
    instance_ = new DataModel();
  }
  return instance_;
}
