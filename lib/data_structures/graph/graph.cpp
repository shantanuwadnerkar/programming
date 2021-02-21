#include "graph.h"


Graph::Graph(const std::vector<graph::Edge>& edges,
            int num_nodes, bool undirected)
    : adj_list_(num_nodes)
{
    for (auto edge : edges)
    {
        adj_list_[edge.src].push_back(edge.dest);
        if (undirected)
        {
            adj_list_[edge.dest].push_back(edge.src);
        }
    }
}

Graph::~Graph()
{
}

void Graph::print()
{
    for (int i=0; i<adj_list_.size(); i++)
    {
        std::cout << "Node (value: " << i << ") -> ";
        for (int j=0; j<adj_list_[i].size(); j++)
        {
            std::cout << adj_list_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

WeightedGraph::WeightedGraph(const edge_t& edges, int num_nodes,
                             bool undirected)
    : adj_list_(num_nodes)
{
    for (auto edge : edges)
    {
        node_t node{std::make_pair(edge.dest, edge.weight)};
        adj_list_[edge.src].push_back(node);

        if (undirected)
        {
            node_t reverse_node{std::make_pair(edge.src, edge.weight)};
            adj_list_[edge.dest].push_back(node);
        }
    }
}

WeightedGraph::~WeightedGraph()
{
}

void WeightedGraph::print()
{
    for (int i=0; i<adj_list_.size(); i++)
    {
        std::cout << "Node (value: " << i << ") -> ";
        for (int j=0; j<adj_list_[i].size(); j++)
        {
            std::cout << "(" << adj_list_[i][j].first << ", " << adj_list_[i][j].second << "), ";
        }
        std::cout << '\n';
    }
}
