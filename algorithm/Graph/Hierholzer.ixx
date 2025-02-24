module;

#include <algorithm>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>

export module Graph.Hierholzer;
import Graph.AdjList;
import Graph.CC;

export namespace graph {

class Hierholzer {
 public:
  explicit Hierholzer(AdjList& graph) : graph_(graph) {}

  std::vector<int> FindEulerCircuit(int start) {
    std::stack<int> stack;  // 当前路径
    std::vector<int> path;  // 存储最终的欧拉回路

    stack.push(start);

    while (!stack.empty()) {
      int currV = stack.top();

      // 如果当前顶点有未访问的边
      auto adjList = graph_.Adj(currV);
      if (!adjList.empty()) {
        int nextV = *adjList.begin();
        graph_.RemoveEdge(currV, nextV);
        stack.push(nextV);
      } else {
        // 如果没有未访问的边，则将当前顶点加入电路
        path.push_back(currV);
        stack.pop();
      }
    }

    // 反转电路以获得正确的顺序
    std::reverse(path.begin(), path.end());
    return path;
  }

  // 检查图是否为欧拉图（所有顶点度数均为偶数）
  bool IsEulerian() {
    for (int i = 0; i < graph_.V(); i++) {
      if (graph_.Adj(i).size() % 2 != 0) {
        return false;
      }
    }

    return true;
  }

 private:
  graph::AdjList graph_;
};
}  // namespace graph
