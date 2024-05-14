#include <iostream>
#include <vector>
#include <algorithm>
#include "basics.h"

// start from 0, not 1
// Time complexity: n*lgn

void naiveBuildHeap(std::vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        size_t k = i;
        while (k > 0 && arr[parent(arr, k)] < arr[k])
        {
            std::swap(arr[k], arr[parent(arr, k)]);
            k = parent(arr, k);
        }
    }
}

void heapifyIt(std::vector<int> &A, int index, int n)
{
    // int n = A.size();
    while (isInternalVertex(A, index)) // while is not leaf
    {
        int largest = index;
        int left = leftKid(index);
        int right = rightKid(index);
        if (left < n && A[left] > A[index])
            largest = left;

        if (right < n && A[right] > A[largest])
            largest = right;

        if (largest != index)
        {
            std::swap(A[largest], A[index]);
            index = largest;
        }
        else
        {
            break;
        }
    }
}

void heapifyRec(std::vector<int> &A, int index)
{
    if (isInternalVertex(A, index))
    {
        int left = leftKid(index);
        int right = rightKid(index);
        int largest = index;
        int n = A.size();
        if (left < n && A[left] > A[index])
            largest = left;

        if (right < n && A[right] > A[largest])
            largest = left;

        if (largest != index)
        {
            std::swap(A[index], A[largest]);
            heapifyRec(A, largest);
        }
    }
}

// Θ(n) Robert Floyd
void buildHeap(std::vector<int> &A)
{
    for (int i = ((A.size() - 1) / 2); i > -1; i--)
    {
        heapifyIt(A, i, A.size());
    }
}

void heapsort(std::vector<int> &A)
{
    buildHeap(A);
    for (int i = (A.size() - 1); i > 0; i--)
    {
        std::swap(A[0], A[i]);
        heapifyIt(A, 0, i);
    }
}

int main()
{
    std::vector<int> A;
    A.push_back(10);
    A.push_back(8);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);
    A.push_back(9);

    // naiveBuildHeap(A);
    // buildHeap(A);
    heapsort(A);

    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A[i] << " ";
    }
}