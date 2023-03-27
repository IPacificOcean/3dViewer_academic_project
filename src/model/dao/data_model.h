//
// Created by Violator Emilie on 3/27/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
#include <vector>

namespace s21 {
class DataModel {
 public:

  const std::vector<double> &GetVertex() const {
	return vertex_;
  }

  void SetVertex(const std::vector<double> &vertex) {
	vertex_ = vertex;
  }

  const std::vector<size_t> &GetFacets() const {
	return facets_;
  }

  void SetFacets(const std::vector<size_t> &facets) {
	facets_ = facets;
  }

 private:
  std::vector<double> vertex_{};
  std::vector<size_t> facets_{};
};

}

#endif //INC_3DVIEWER_V2_0_SRC_MODEL_DAO_DATA_MODEL_H_
