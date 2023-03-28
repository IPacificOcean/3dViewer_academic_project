//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#include <vector>

namespace s21 {
class DataModel {
 public:
  const std::vector<double> &GetVertex() const { return vertex_; }
  void SetVertex(const std::vector<double> &vertex) { vertex_ = vertex; }

  const std::vector<size_t> &GetFacets() const { return facets_; }
  void SetFacets(const std::vector<size_t> &facets) { facets_ = facets; }

  size_t GetVertexSize() const { return vertex_size_; }
  void SetVertexSize(size_t vertex_size) { vertex_size_ = vertex_size; }

  size_t GetFacetsSize() const { return facets_size_; }
  void SetFacetsSize(size_t facets_size) { facets_size_ = facets_size; }

 private:
  std::vector<double> vertex_{};
  std::vector<size_t> facets_{};
  size_t vertex_size_{};
  size_t facets_size_{};
};

}  // namespace s21

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
