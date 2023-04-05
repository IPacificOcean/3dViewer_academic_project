//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#include <string>
#include <vector>


// TODO нужно инкапсулировать сеттеры от view, можно добавить friend классы
namespace s21 {
class DataModel {
 public:
  std::vector<double> &GetVertex()  { return vertex_; }
  void SetVertex(const std::vector<double> &vertex) { vertex_ = vertex; }

  std::vector<unsigned int> &GetFacets()  { return facets_; }
  void SetFacets(const std::vector<unsigned int> &facets) { facets_ = facets; }

  size_t GetVertexSize() const { return vertex_size_; }
  void SetVertexSize(size_t vertex_size) { vertex_size_ = vertex_size; }

  size_t GetFacetsSize() const { return facets_size_; }
  void SetFacetsSize(size_t facets_size) { facets_size_ = facets_size; }

  const std::string &GetFileName() const { return file_name_; }
  void SetFileName(const std::string &file_name) { file_name_ = file_name; }
  static DataModel *GetInstance();

  ~DataModel() { delete instance_; }

 private:
  DataModel() = default;
  static inline DataModel *instance_;
  std::vector<double> vertex_{};
  std::vector<unsigned int> facets_{};
  size_t vertex_size_{};
  size_t facets_size_{};
  std::string file_name_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
