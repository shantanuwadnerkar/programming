#include <iostream>
#include <queue>
#include <vector>

#include "graph.h"

class PQComparison
{
public:
    PQComparison()
    {
    }

    bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
    {
        return (lhs.second > rhs.second);
    }
};


bool dijkstra(const WeightedGraph& graph)
{
    using node_t = WeightedGraph::node_t;
    std::vector<node_t> seen;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, PQComparison> pq;
    int goal{5};
    pq.push(std::make_pair<int, int>(0, 0));

    while (!pq.empty())
    {
        node_t node{pq.top()};
        pq.pop();
        seen.push_back(node);
        if (node.first == goal)
        {
            return true;
        }

        for ()
    }
}


int main()
{
    // std::vector<int> init{3, 7, 8, 2, 9, 1};
    // std::priority_queue<int, std::vector<int>, std::greater<int>> pq(init.cbegin(), init.cend());
    
    // std::cout << pq.size() << '\n';
    // for (int idx=0, n=pq.size(); idx<n; idx++)
    // {
    //     std::cout << pq.top() << ' ';
    //     pq.pop();
    // }
    // std::cout << '\n';

    // std::vector<graph::Edge> edges{
    //     {0, 1}, {0, 4}, {0, 5}, {1, 3},
    //     {1, 4}, {2, 1}, {3, 2}, {3, 4}
    // };

    // Graph grph(edges, 6);
    // grph.print();

    // 0 -> (1, 50), (2, 45), (3, 10)
    // 1 -> (2, 10), (3, 15)
    // 2 -> (4, 30)
    // 3 -> (0, 10), (4, 15)
    // 4 -> (1, 20), (2, 35)
    // 5 -> (4, 3)

    WeightedGraph::edge_t w_edges{
        {0, 1, 50}, {0, 2, 45}, {0, 3, 10},
        {1, 2, 10}, {1, 3, 15}, {2, 4, 30},
        {3, 0, 10}, {3, 4, 15},
        {4, 1, 20}, {4, 2, 35},
        {5, 4, 3}
    };

    WeightedGraph w_graph{w_edges, 6};
    // w_graph.print();

    // dijkstra(w_graph)

    return 0;
}
