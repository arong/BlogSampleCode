module;
#include <set>
#include <string>
#include <vector>
export module Graph.Interface;

export namespace graph {
typedef unsigned Vertex;
typedef int Weight;
typedef std::pair<Vertex, Vertex> Edge;
typedef std::tuple<Vertex, Vertex, Weight> WeightedEdge;

struct Graph {
  virtual ~Graph() = default;

  // 获取顶点数量
  [[nodiscard]] virtual size_t V() const = 0;

  // 获取边数量
  [[nodiscard]] virtual size_t E() const = 0;

  // 该图是有向图吗?
  [[nodiscard]] virtual bool Directed() const = 0;

  // 该图是带权图吗?
  [[nodiscard]] virtual bool Weighted() const = 0;

  // 获取顶点u的所有邻接顶点
  [[nodiscard]] virtual std::set<Vertex> Adj(Vertex u) const = 0;

  // 顶点u,v之间是否存在一条边
  [[nodiscard]] virtual bool HasEdge(Vertex u, Vertex v) const = 0;

  // 添加边u,v
  virtual void AddEdge(Vertex u, Vertex v) = 0;

  // 添加带权边u,v
  virtual void AddEdge(Vertex u, Vertex v, Weight w) = 0;

  // 将图以dot格式输出(Graphviz支持的格式), 可用于可视化
  [[nodiscard]] virtual std::string FormatAsDot() const = 0;
};

}  // namespace graph
