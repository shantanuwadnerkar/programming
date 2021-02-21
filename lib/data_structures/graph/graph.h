// Source:
// https://www.techiedelight.com/graph-implementation-using-stl/
// Templatized implementation: https://gist.github.com/Amadeeus/00baef6c662f30447cb15a125314a5cf
// Weighted graphs: https://gist.github.com/quickgrid/b420c8606b553819c001cb45beddfc58

#pragma once

#include <iostream>
#include <vector>


namespace graph
{
    // Haven't used this
    // Can be used for storing node names
    // Currently node names are not supported, only indices
    template <typename T>
    struct Node
    {
        T data;
        std::vector<int> adjIndices;
    };

    struct Edge
    {
        int src, dest;
    };

    struct WeightedEdge
    {
        int src, dest, weight;
    };
}

class Graph
{
public:
    Graph(const std::vector<graph::Edge>& edges,
            int num_nodes, bool undirected = false);
    ~Graph();
    void print();
    // void addEdge();
    // void addNode();

private:
    std::vector<std::vector<int>> adj_list_;
};

class WeightedGraph
{
public:
    using node_t = std::pair<int, int>;
    using edge_t = std::vector<graph::WeightedEdge>;
    using adj_list_t = std::vector<std::vector<node_t>>;

    adj_list_t adj_list_;

    WeightedGraph(const edge_t& edges,
                  int num_nodes, bool undirected = false);
    ~WeightedGraph();
    void print();

private:
};
