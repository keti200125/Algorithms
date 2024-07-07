#include "Graph.h"

Graph::Graph(size_t n,bool oriented=false): adj(size), size(n),isOriented(oriented) {}

void Graph::addEdge(int from,int to)
{
    adj[from].push_back(to);
    if(!isOriented)
    {
        adj[to].push_back(from);
    }
    
}

