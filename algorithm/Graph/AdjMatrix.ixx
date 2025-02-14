module;

#include <fmt/core.h>
#include <fmt/ranges.h>

#include <set>
#include <stdexcept>
#include <vector>

export module Graph.AdjMatrix;
export import Graph.Interface;

export namespace graph {
class AdjMatrix : public Graph {
 public:
  ~AdjMatrix() = default;
  AdjMatrix() = default;
  AdjMatrix(std::size_t size, const std::vector<Edge>& edges, bool directed)
      : directed_(directed), weighted_(false) {
    if (size == 0) return;
    matrix_.resize(size, std::vector<int>(size, 0));
    for (auto& [u, v] : edges) {
      AddEdge(u, v);
    }
  }
  AdjMatrix(size_t size, const std::vector<WeightedEdge>& edges, bool directed)
      : directed_(directed), weighted_(true) {
    if (size == 0) return;
    matrix_.resize(size, std::vector<int>(size, 0));
    for (auto& [u, v, w] : edges) {
      AddEdge(u, v, w);
    }
  }
  AdjMatrix(size_t size, bool directed, bool weighted)
      : directed_(directed), weighted_(weighted) {
    if (size == 0) return;
    matrix_.resize(size, std::vector<int>(size, 0));
  }
  void Reset(size_t size, bool directed, bool weighted) {
    directed_ = directed;
    weighted_ = weighted;
    edge_num_ = 0;
    matrix_.clear();
    matrix_.resize(size, std::vector<int>(size, 0));
  }
  [[nodiscard]] size_t V() const final { return matrix_.size(); }
  [[nodiscard]] size_t E() const final { return edge_num_; }
  [[nodiscard]] bool Directed() const final { return directed_; }
  [[nodiscard]] bool Weighted() const final { return weighted_; }
  [[nodiscard]] bool HasEdge(Vertex u, Vertex v) const final {
    validateVertex(u);
    validateVertex(v);
    return matrix_[u][v] != 0;
  }
  [[nodiscard]] std::set<Vertex> Adj(unsigned u) const final {
    validateVertex(u);
    std::set<Vertex> adj;
    for (Vertex v = 0; v < matrix_.size(); ++v) {
      if (matrix_[u][v] != 0) {
        adj.insert(v);
      }
    }
    return adj;
  }

  [[nodiscard]] Weight GetWeight(Vertex u, Vertex v) const {
    validateVertex(u);
    validateVertex(v);
    if (!weighted_) throw std::runtime_error("unweighted graph");
    if (matrix_[u][v] == 0) {
      throw std::runtime_error("no such edge");
    }
    return matrix_[u][v];
  }
  void UpdateWeight(unsigned u, unsigned v, int diff) {
    validateVertex(u);
    validateVertex(v);
    if (!weighted_) throw std::runtime_error("unweighted graph");
    if (matrix_[u][v] == 0) {
      throw std::runtime_error("no such edge");
    }
    matrix_[u][v] += diff;
    if (!directed_) {
      matrix_[v][u] += diff;
    }
  }
  std::vector<WeightedEdge> GetWeightEdges() const {
    if (!weighted_) throw std::runtime_error("unweighted graph");
    std::vector<WeightedEdge> edges;
    for (Vertex u = 0; u < matrix_.size(); u++) {
      Vertex v = 0;
      if (!directed_) {
        v = u + 1;
      }
      for (; v < matrix_.size(); v++) {
        if (matrix_[u][v] != 0) {
          edges.emplace_back(u, v, matrix_[u][v]);
        }
      }
    }
    return edges;
  }
  void AddEdge(Vertex u, Vertex v) final {
    validateVertex(u);
    validateVertex(v);
    if (u == v) throw std::runtime_error("self loop");
    if (weighted_)
      throw std::runtime_error("weighted graph should use AddEdge(u,v,w)");

    if (matrix_[u][v] != 0) throw std::runtime_error("parallel edge");

    matrix_[u][v] = 1;
    if (!directed_) {
      matrix_[v][u] = 1;
    }
    edge_num_++;
  }
  void AddEdge(Vertex u, Vertex v, Weight w) final {
    validateVertex(u);
    validateVertex(v);

    if (!weighted_) {
      throw std::runtime_error("unweighted graph should use AddEdge(u,v)");
    }
    if (u == v) {
      throw std::runtime_error("self loop");
    }
    if (matrix_[u][v] != 0) {
      throw std::runtime_error("parallel edge");
    }
    matrix_[u][v] = w;
    if (!directed_) {
      matrix_[v][u] = w;
    }
    edge_num_++;
  }
  [[nodiscard]] std::string FormatAsDot() const final {
    std::string dot;
    std::string dash("--");
    if (directed_) {
      dot.append("digraph AdjMatrix {\n");
      dash = "->";
    } else {
      dot.append("graph AdjMatrix {\n");
    }
    dot.append("\trankdir=\"LR\";\n");
    dot.append("\tnode [shape=circle;]\n");
    auto inserter = std::back_inserter(dot);
    for (Vertex u = 0; u < matrix_.size(); u++) {
      fmt::format_to(inserter, "\t{};\n", u);
    }

    for (Vertex u = 0; u < matrix_.size(); u++) {
      for (Vertex v = 0; v < matrix_.size(); v++) {
        if (matrix_[u][v] != 0) {
          if (directed_ || u < v) {
            if (weighted_) {
              fmt::format_to(inserter, "\t{} {} {} [label={}];\n", u, dash, v,
                             matrix_[u][v]);
            } else {
              fmt::format_to(inserter, "\t{} {} {};\n", u, dash, v);
            }
          }
        }
      }
    }
    dot.append("}\n");
    return dot;
  }

 private:
  void validateVertex(Vertex u) const {
    if (u >= matrix_.size()) throw std::out_of_range("vertex out of range");
  }

 private:
  bool directed_ = false;
  bool weighted_ = false;
  size_t edge_num_ = 0;
  std::vector<std::vector<int>> matrix_;
};
}  // namespace graph
