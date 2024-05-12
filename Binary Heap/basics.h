#include <iostream>
#include <vector>

int parent(std::vector<int> binaryHeap, size_t i)
{
    if (i == 1 || i==2 || i==0)
        return 0;
    if(i%2==0)
        return ((i/2)-1); // start from 0
    return (i / 2);
}

// if 2*i < n
int leftKid(size_t i)
{
    if(i==0)
    {
        return 1;
    }
    return 2 * i+1; // because we start from index 0, 2*i from 1
}

// if 2*i +1 < n
int rightKid(size_t i)
{
    if(i==0)
    {
        return 2;
    }
    return 2 * i + 2; //because we start from index 0, 2*i +1 from 1
}

/*
size_t level(size_t i)
{
    return log2(i);
}
*/

bool isLeaf(std::vector<int> binaryHeap, size_t i)
{
    return (i > ((binaryHeap.size()-1) / 2)); // index 0
}

bool isInternalVertex(std::vector<int> binaryHeap, size_t i)
{
    return !(isLeaf(binaryHeap, i));
}

bool isRoot(size_t i)
{
    return i == 0;
}
