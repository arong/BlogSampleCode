module;
#include <fmt/core.h>

#include <queue>
#include <stdexcept>
#include <string>
export module Graph.Bipartite;
import Graph.Interface;
import Graph.CC;
export namespace graph {
enum class Color {
  Unknown,
  Red,
  Black,
};
bool ColorDFS(const Graph& graph, std::vector<Color>& colors, Vertex start,
              Color color) {
  colors[start] = color;
  for (auto v : graph.Adj(start)) {
    if (colors[v] == color) return false;
    if (colors[v] == Color::Unknown) {
      if (!ColorDFS(graph, colors, v,
                    color == Color::Red ? Color::Black : Color::Red)) {
        return false;
      }
    }
  }
  return true;
}

bool IsBipartite(const Graph& graph) {
  std::vector<Color> colors(graph.V(), Color::Unknown);
  auto cc = CC(graph);
  if (cc != 1) return false;
  return ColorDFS(graph, colors, 0, Color::Red);
}

class Bipartite {
 public:
  explicit Bipartite(const Graph& graph) : graph_(graph) {
    colors_.resize(graph_.V(), Color::Unknown);
    auto cc = CC(graph_);
    is_bipartite_ = (cc == 1) && ColorDFS(graph_, colors_, 0, Color::Red);
  }
  bool IsBipartite() const { return is_bipartite_; }

  std::vector<Color> Colors() const { return colors_; }

  std::string FormatAsDot() const {
    if (!is_bipartite_) return {};
    std::string dot;
    dot.append("graph BipartiteGraph {\n");
    dot.append("\tnode [shape=circle,style=filled];\n");
    dot.append("\trankDir=LR;\n");
    auto inserter = std::back_inserter(dot);
    for (Vertex v = 0; v < graph_.V(); ++v) {
      fmt::format_to(inserter, "\t{}[color={}];\n", v,
                     (colors_[v] == Color::Red ? "red" : "green"));
    }
    for (Vertex v = 0; v < graph_.V(); ++v) {
      for (auto w : graph_.Adj(v)) {
        if (v < w) {
          fmt::format_to(inserter, "\t{} -- {};\n", v, w);
        }
      }
    }
    dot.append("}\n");
    return dot;
  }

 private:
  const Graph& graph_;
  bool is_bipartite_ = false;
  std::vector<Color> colors_;
};

}  // namespace graph
