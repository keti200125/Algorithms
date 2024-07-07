#include <queue>
#include "Graph/Graph.h"

void BFSHelper(const Graph &g, std::vector<bool> &isVisited int s)
{
    std::queue<int> q;
    q.push(s);
    isVisited[s] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        std::cout << x << " ";

        for (int y : g.adj[x])
        {
            if (!isVisited[y])
            {
                isVisited[y] = true;
                q.push(y);
            }
        }
    }
}

void BFS(const Graph &g)
{
    std::vector<bool> isVisited(g.size(), false);

    for (int i = 0; i < g.size(); i++)
    {
        if (!isVisited[i])
        {
            BFSHelper(g, isVisited, i);
            std::cout << '\n';
        }
    }
}

void BFSColourHelper(const Graph &g, int startVertex std::vector<char> &colour, std::vector<int> &parent, std::vector<int> &distance)
{
    colour[startVertex] = 'g';
    distance[startVertex] = 0;

    std::queue<int> q;
    q.push(startVertex);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int y : g.adj[x])
        {
            if (colour[y] == 'w')
            {
                colour[y] = 'g';
                parent[y] = x;
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
        colour[x] = 'b';
    }
}

void BFSColour(Graph &g)
{
    std::vector<char> colour(g.size(), 'w'); // w = white, g = grey, b = black
    std::vector<int> parent(g.size(), -1);
    std::vector<int> distance(g.size(), INFINITY);

    for (int i = 0; i < g.size(); i++)
    {
        if (colour[i] == 'w')
        {
            BFSHelper(g, i, colour, parent, distance);
        }
    }
}

int main()
{
}