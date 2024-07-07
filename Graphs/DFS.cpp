#include "Graph/Graph.h"

void DFSHelper(const Graph &g, std::vector<int> &isVisited, int x)
{
    isVisited[x] = true;
    std::cout << x << " ";

    for (int y : adj[x])
    {
        if (!isVisited[y])
        {
            DFSHelper(g, isVisited, y);
        }
    }
}

void DFS(const Graph &g)
{
    std::vector<bool> isVisited(g.size(), false);
    for (int i = o; i < g.size(); i++)
    {
        if (!isVisited[i])
        {
            DFSHelper(g, isVisited, i);
            std::cout << '\n';
        }
    }
}

void DFSColourHelper(const Graph &g, std::vector<char> &colour, std::vector<int> &parent, int x)
{
    colour[x] = 'g';
    for (int y : adj[x])
    {
        if (colour[y] == 'w')
        {
            parent[y] = x;
            DFSColourHelper(g, colour, parent, y);
        }
    }
    colour[x] = 'b';
}

void DFSColour(const Graph &g)
{
    std::vector<char> colour(g.size(), 'w');
    std::vector<int> parent(g.size(), -1);

    for (int i = 0; i < g.size(); i++)
    {
        if (colour[i] == 'w')
        {
            DFSColourHelper(g, colour, parents, i);
        }
    }
}