#include "Graph/Graph.h"

int time = 0;
int l = n - 1;
int n = g.size();
std::vector<int> topoSort(n, 0);
std::vector<char> colour(n, 'w');
std::vector<int> parent(n, 0);

void topoSortTarjan(const Graph &g)
{
    for (i = 0; i < n; i++)
    {
        if (colour[y] == 'w')
        {
            topoSortTarjanHelper(g, y);
        }
    }
}

void topoSortTarjanHelper(const Graph &g, int x)
{
    colour[x] = 'g';
    time++;
    for (int y : g.adj[x])
    {
        if (colour[y] == 'w')
        {
            parent[y] = x;
            topoSortTarjanHelper(G, y);
        }
    }
    colour[x] = 'b';
    time++;
    l[x] = time;
    topoSort[l] = x;
    l--;
}