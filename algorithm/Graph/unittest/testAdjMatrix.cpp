#include <gtest/gtest.h>

import Graph.AdjMatrix;
using namespace graph;

TEST(AdjMatrixTest, Constructor) {
  AdjMatrix graph(5, false, false);
  EXPECT_EQ(graph.V(), 5);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_FALSE(graph.Directed());
  EXPECT_FALSE(graph.Weighted());
}

TEST(AdjMatrixTest, AddEdge_Unweighted) {
  AdjMatrix graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_TRUE(graph.HasEdge(1, 2));
  EXPECT_FALSE(graph.HasEdge(0, 2));
  EXPECT_EQ(graph.E(), 2);
}

TEST(AdjMatrixTest, AddEdge_Weighted) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(1, 2, 20);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_TRUE(graph.HasEdge(1, 2));
  EXPECT_FALSE(graph.HasEdge(0, 2));
  EXPECT_EQ(graph.GetWeight(0, 1), 10);
  EXPECT_EQ(graph.GetWeight(1, 2), 20);
  EXPECT_EQ(graph.E(), 2);
}

TEST(AdjMatrixTest, DirectedGraph) {
  AdjMatrix graph(5, true, false);
  graph.AddEdge(0, 1);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_FALSE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjMatrixTest, WeightedDirectedGraph) {
  AdjMatrix graph(5, true, true);
  graph.AddEdge(0, 1, 10);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_FALSE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.GetWeight(0, 1), 10);
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjMatrixTest, GetWeight) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  EXPECT_EQ(graph.GetWeight(0, 1), 10);
  EXPECT_THROW(graph.GetWeight(0, 2), std::runtime_error);
}

TEST(AdjMatrixTest, UpdateWeight) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  graph.UpdateWeight(0, 1, 5);
  EXPECT_EQ(graph.GetWeight(0, 1), 15);
  EXPECT_THROW(graph.UpdateWeight(0, 2, 5), std::runtime_error);
}

TEST(AdjMatrixTest, GetWeightEdges) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(1, 2, 20);
  auto edges = graph.GetWeightEdges();
  EXPECT_EQ(edges.size(), 2);
  EXPECT_EQ(edges[0], std::make_tuple(0, 1, 10));
  EXPECT_EQ(edges[1], std::make_tuple(1, 2, 20));
}

TEST(AdjMatrixTest, Reset) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  graph.Reset(3, true, false);
  EXPECT_EQ(graph.V(), 3);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_TRUE(graph.Directed());
  EXPECT_FALSE(graph.Weighted());
}

TEST(AdjMatrixTest, Adj) {
  AdjMatrix graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  auto adj = graph.Adj(0);
  EXPECT_EQ(adj.size(), 2);
  EXPECT_TRUE(adj.find(1) != adj.end());
  EXPECT_TRUE(adj.find(2) != adj.end());
}

TEST(AdjMatrixTest, FormatAsDot) {
  AdjMatrix graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(1, 2, 20);
  std::string dot = graph.FormatAsDot();
  EXPECT_TRUE(dot.find("graph AdjMatrix {") != std::string::npos);
  EXPECT_TRUE(dot.find("0 -- 1 [label=10];") != std::string::npos);
  EXPECT_TRUE(dot.find("1 -- 2 [label=20];") != std::string::npos);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
