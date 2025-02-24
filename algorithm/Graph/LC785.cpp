#include <vector>
using namespace std;

class Solution {
  bool ColorDFS(vector<vector<int>>& graph, std::vector<int>& colors, int start,
                int color) {
    colors[start] = color;
    for (auto v : graph[start]) {
      if (colors[v] == color) return false;
      if (colors[v] == -1) {
        if (!ColorDFS(graph, colors, v, 1 - color)) {
          return false;
        }
      }
    }
    return true;
  }

 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size(), -1);
    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] == -1) {
        if (!ColorDFS(graph, colors, i, 0)) {
          return false;
        }
      }
    }
    return true;
  }
};
