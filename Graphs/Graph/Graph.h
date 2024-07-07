#ifndef GRAPH
#define GRAPH

#include<iostream>
#include<vector>
#include<list>

class Graph
{
    private:
    std::vector<std::list<int>> adj;
    bool isOriented;
    size_t size;

    public:
    Graph(size_t size,bool oriented);
    void addEdge(int from,int to);
};



#endif