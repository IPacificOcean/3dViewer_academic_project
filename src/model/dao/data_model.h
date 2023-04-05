//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#include <string>
#include <vector>
#include "../model/kernel/parser.h"


// TODO нужно инкапсулировать сеттеры от view, можно добавить friend классы
namespace s21 {
class DataModel {
 public:
  const std::vector<double> &GetVertex() const { return vertex_; }
  const std::vector<unsigned int> &GetFacets()  const { return facets_; }

  size_t GetVertexSize() const { return vertex_.size(); }

  size_t GetFacetsSize() const { return facets_.size(); }

  const std::string &GetFileName() const { return file_name_; }

  static DataModel *GetInstance();

  ~DataModel() { delete instance_; }

 private:
  DataModel() = default;
  static inline DataModel *instance_;
  std::vector<double> vertex_{};
  std::vector<unsigned int> facets_{};
//  size_t vertex_size_{};
//  size_t facets_size_{};
  std::string file_name_{};

  friend class Parser;
  std::vector<double> &AccessVertex()  { return vertex_; }
  std::vector<unsigned int> &AccessFacets()  { return facets_; }
  std::string &AccessFileName()  { return file_name_; }

};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
