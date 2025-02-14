#include <gtest/gtest.h>

import Graph.AdjList;
using namespace graph;

TEST(AdjListTest, ConstructorTest) {
  AdjList graph(5, false, false);
  EXPECT_EQ(graph.V(), 5);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_FALSE(graph.Directed());
  EXPECT_FALSE(graph.Weighted());
}

TEST(AdjListTest, WeightedConstructorTest) {
  AdjList graph(5, false, true);
  EXPECT_EQ(graph.V(), 5);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_FALSE(graph.Directed());
  EXPECT_TRUE(graph.Weighted());
}

TEST(AdjListTest, DirectedConstructorTest) {
  AdjList graph(5, true, false);
  EXPECT_EQ(graph.V(), 5);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_TRUE(graph.Directed());
  EXPECT_FALSE(graph.Weighted());
}

TEST(AdjListTest, AddEdgeTest) {
  AdjList graph(5, false, false);
  graph.AddEdge(0, 1);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_TRUE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjListTest, AddWeightedEdgeTest) {
  AdjList graph(5, false, true);
  graph.AddEdge(0, 1, 10);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_TRUE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.GetWeight(0, 1), 10);
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjListTest, DirectedAddEdgeTest) {
  AdjList graph(5, true, false);
  graph.AddEdge(0, 1);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_FALSE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjListTest, DirectedAddWeightedEdgeTest) {
  AdjList graph(5, true, true);
  graph.AddEdge(0, 1, 10);
  EXPECT_TRUE(graph.HasEdge(0, 1));
  EXPECT_FALSE(graph.HasEdge(1, 0));
  EXPECT_EQ(graph.GetWeight(0, 1), 10);
  EXPECT_EQ(graph.E(), 1);
}

TEST(AdjListTest, UpdateWeightTest) {
  AdjList graph(5, true, true);
  graph.AddEdge(0, 1, 10);
  graph.UpdateWeight(0, 1, 5);
  EXPECT_EQ(graph.GetWeight(0, 1), 15);
}

TEST(AdjListTest, GetWeightEdgesTest) {
  AdjList graph(5, true, true);
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(1, 2, 20);
  auto edges = graph.GetWeightEdges();
  EXPECT_EQ(edges.size(), 2);
  EXPECT_EQ(edges[0], std::make_tuple(0, 1, 10));
  EXPECT_EQ(edges[1], std::make_tuple(1, 2, 20));
}

TEST(AdjListTest, AdjTest) {
  AdjList graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.AddEdge(0, 2);
  auto adj = graph.Adj(0);
  EXPECT_EQ(adj.size(), 2);
  EXPECT_TRUE(adj.find(1) != adj.end());
  EXPECT_TRUE(adj.find(2) != adj.end());
}

TEST(AdjListTest, ResetTest) {
  AdjList graph(5, false, false);
  graph.AddEdge(0, 1);
  graph.Reset(3, true, true);
  EXPECT_EQ(graph.V(), 3);
  EXPECT_EQ(graph.E(), 0);
  EXPECT_TRUE(graph.Directed());
  EXPECT_TRUE(graph.Weighted());
}

TEST(AdjListTest, FormatAsDotTest) {
  AdjList graph(3, false, true);
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(1, 2, 20);
  std::string dot = graph.FormatAsDot();
  EXPECT_TRUE(dot.find("0 -- 1 [label=10];") != std::string::npos);
  EXPECT_TRUE(dot.find("1 -- 2 [label=20];") != std::string::npos);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
