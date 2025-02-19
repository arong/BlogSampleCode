module;

#include <algorithm>
#include <map>
#include <stack>
#include <stdexcept>
#include <vector>

export module Graph.Tarjan;
import Graph.AdjList;
import Graph.Interface;

export namespace graph {

class Tarjan {
 public:
  Tarjan(const Graph& graph) : graph_(graph) {
    if (!graph.Directed()) throw std::runtime_error("graph is not directed");
  }

  std::vector<std::vector<int>> GetSCC() {
    const auto n = graph_.V();
    indices.assign(n, -1);
    lowLinks.assign(n, -1);
    onStack.assign(n, false);
    index = 0;
    for (Vertex i = 0; i < graph_.V(); ++i) {
      if (indices[i] == -1) {
        strongconnect(i);
      }
    }
    return sccs;
  }

 private:
  void strongconnect(int v) {
    indices[v] = index;
    lowLinks[v] = index;
    index++;
    stack.push(v);
    onStack[v] = true;

    for (int w : graph_.Adj(v)) {
      if (indices[w] == -1) {
        strongconnect(w);
        lowLinks[v] = std::min(lowLinks[v], lowLinks[w]);
      } else if (onStack[w]) {
        lowLinks[v] = std::min(lowLinks[v], indices[w]);
      }
    }

    if (lowLinks[v] == indices[v]) {
      std::vector<int> scc;
      int w;
      do {
        w = stack.top();
        stack.pop();
        onStack[w] = false;
        scc.push_back(w);
      } while (w != v);
      sccs.push_back(scc);
    }
  }

  const Graph& graph_;
  std::vector<int> indices;
  std::vector<int> lowLinks;
  std::vector<bool> onStack;
  std::stack<int> stack;
  std::vector<std::vector<int>> sccs;
  int index;
};

}  // namespace graph
