module;
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>
export module Graph.AdjList;
export import Graph.Interface;

export namespace graph {
class AdjList : public Graph {
 public:
  ~AdjList() = default;
  AdjList() = default;
  AdjList(std::size_t size, const std::vector<Edge>& edges, bool directed)
      : directed_(directed), weighted_(false) {
    if (size == 0) return;
    adj_.resize(size, std::set<Vertex>{});
    for (auto& [u, v] : edges) {
      AddEdge(u, v);
    }
  }
  AdjList(size_t size, const std::vector<WeightedEdge> edges, bool directed)
      : directed_(directed), weighted_(true) {
    if (size == 0) return;
    adj_.resize(size, std::map<Vertex, Weight>{});
    for (auto& [u, v, w] : edges) {
      AddEdge(u, v, w);
    }
  }
  AdjList(size_t size, bool directed, bool weighted)
      : directed_(directed), weighted_(weighted) {
    if (size == 0) return;
    if (weighted) {
      adj_.resize(size, std::map<Vertex, Weight>{});
    } else {
      adj_.resize(size, std::set<Vertex>{});
    }
  }
  void Reset(size_t size, bool directed, bool weighted) {
    directed_ = directed;
    weighted_ = weighted;
    edge_num_ = 0;
    if (weighted) {
      adj_.clear();
      adj_.resize(size, std::map<Vertex, Weight>{});
    } else {
      adj_.clear();
      adj_.resize(size, std::set<Vertex>{});
    }
  }
  [[nodiscard]] size_t V() const final { return adj_.size(); }
  [[nodiscard]] size_t E() const final { return edge_num_; }
  [[nodiscard]] bool Directed() const final { return directed_; }
  [[nodiscard]] bool Weighted() const final { return weighted_; }
  [[nodiscard]] bool HasEdge(Vertex u, Vertex v) const final {
    validateVertex(u);
    validateVertex(v);
    if (weighted_) {
      return std::get<AdjWeighted>(adj_[u]).contains(v);
    } else {
      return std::get<AdjUnWeighted>(adj_[u]).contains(v);
    }
  }
  [[nodiscard]] std::set<Vertex> Adj(unsigned u) const final {
    validateVertex(u);
    if (weighted_) {
      std::set<Vertex> adj;
      for (auto& [v, w] : std::get<AdjWeighted>(adj_[u])) {
        adj.insert(v);
      }
      return adj;
    } else {
      return std::get<AdjUnWeighted>(adj_[u]);
    }
  }
  [[nodiscard]] Weight GetWeight(Vertex u, Vertex v) const {
    validateVertex(u);
    validateVertex(v);
    if (!weighted_) throw std::runtime_error("unweighted graph");
    auto& adj = std::get<AdjWeighted>(adj_[u]);
    auto it = adj.find(v);
    if (it == adj.end()) {
      throw std::runtime_error("no such edge");
    }
    return it->second;
  }
  void UpdateWeight(unsigned u, unsigned v, int diff) {
    validateVertex(u);
    validateVertex(v);
    if (!weighted_) throw std::runtime_error("unweighted graph");
    auto& adj = std::get<AdjWeighted>(adj_[u]);
    auto it = adj.find(v);
    if (it == adj.end()) {
      throw std::runtime_error("no such edge");
    }
    it->second += diff;
  }
  std::vector<WeightedEdge> GetWeightEdges() const {
    if (!weighted_) throw std::runtime_error("unweighted graph");
    std::vector<WeightedEdge> edges;
    for (Vertex u = 0; u < adj_.size(); u++) {
      for (auto& [v, w] : std::get<AdjWeighted>(adj_[u])) {
        edges.emplace_back(u, v, w);
      }
    }
    return edges;
  }
  void AddEdge(Vertex u, Vertex v) final {
    validateVertex(u);
    validateVertex(v);
    if (u == v) throw std::runtime_error("self loop");
    if (weighted_) {
      throw std::runtime_error("weighted graph should use AddEdge(u,v,w)");
    }

    auto [it, success] = std::get<AdjUnWeighted>(adj_[u]).insert(v);
    if (!success) throw std::runtime_error("parallel edge");

    if (!directed_) {
      std::get<AdjUnWeighted>(adj_[v]).insert(u);
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
    auto [it, success] = std::get<AdjWeighted>(adj_[u]).insert({v, w});
    if (!success) {
      throw std::runtime_error("parallel edge");
    }
    if (!directed_) {
      std::get<AdjWeighted>(adj_[v]).insert({u, w});
    }
    edge_num_++;
  }
  [[nodiscard]] std::string FormatAsDot() const final {
    std::string dot;
    std::string dash("--");
    if (directed_) {
      dot.append("digraph AdjList {\n");
      dash = "->";
    } else {
      dot.append("graph AdjList {\n");
    }
    dot.append("\trankdir=\"LR\";\n");
    dot.append("\tnode [shape=circle;]\n");
    auto inserter = std::back_inserter(dot);
    for (Vertex u = 0; u < adj_.size(); u++) {
      fmt::format_to(inserter, "\t{};\n", u);
    }

    for (Vertex u = 0; u < adj_.size(); u++) {
      if (weighted_) {
        for (auto& [v, w] : std::get<AdjWeighted>(adj_[u])) {
          if (directed_ || u < v) {
            fmt::format_to(inserter, "\t{} {} {} [label={}];\n", u, dash, v, w);
          }
        }
      } else {
        for (auto v : std::get<AdjUnWeighted>(adj_[u])) {
          if (directed_ || u < v) {
            fmt::format_to(inserter, "\t{} {} {};\n", u, dash, v);
          }
        }
      }
    }
    dot.append("}\n");
    return dot;
  }

 private:
  void validateVertex(Vertex u) const {
    if (u >= adj_.size()) throw std::out_of_range("vertex out of range");
  }

 private:
  bool directed_ = false;
  bool weighted_ = false;
  size_t edge_num_ = 0;
  using AdjUnWeighted = std::set<Vertex>;
  using AdjWeighted = std::map<Vertex, Weight>;
  using AdjElement = std::variant<AdjUnWeighted, AdjWeighted>;
  std::vector<AdjElement> adj_;
};
}  // namespace graph
