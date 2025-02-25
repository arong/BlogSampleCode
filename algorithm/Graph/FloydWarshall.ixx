module;

#include <algorithm>
#include <climits>
#include <vector>

export module Graph.FloydWarshall;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {
typedef std::vector<std::vector<int>> AdjacencyMatrix;

class FloydWarshall {
 public:
  explicit FloydWarshall(const AdjList& graph) {
    initialize(graph);
    compute();
  }

  AdjacencyMatrix GetASSP() { return adj_; }

 private:
  void initialize(const AdjList& graph) {
    const auto n = graph.V();
    adj_ = AdjacencyMatrix(n, std::vector<int>(n, INT_MAX));
    pre_ = AdjacencyMatrix(n, std::vector<int>(n, -1));
    for (Vertex i = 0; i < n; ++i) {
      for (Vertex j = 0; j < n; ++j) {
        if (i == j) {
          adj_[i][j] = 0;
          pre_[i][j] = i;
        } else if (auto w = graph.HasEdge(i, j) ? graph.GetWeight(i, j) : 0;
                   w > 0) {
          adj_[i][j] = w;
          pre_[i][j] = i;
        }
      }
    }
  }

  void compute() {
    auto n = adj_.size();
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (adj_[i][k] + adj_[k][j] < adj_[i][j]) {
            adj_[i][j] = adj_[i][k] + adj_[k][j];
            pre_[i][j] = pre_[k][j];
          }
        }
      }
    }
  }

 private:
  AdjacencyMatrix adj_;
  AdjacencyMatrix pre_;
};
}  // namespace graph
