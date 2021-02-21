#include "graph.h"


int main()
{
    std::vector<graph::Edge> edges{
        {0, 1}, {0, 4}, {0, 5}, {1, 3},
        {1, 4}, {2, 1}, {3, 2}, {3, 4}
    };

    Graph grph(edges, 6, true);
    grph.print();

    return 0;
}
