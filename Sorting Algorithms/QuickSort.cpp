#include<iostream>

//Divide and Conquer

// 2 6538710 pivot=3
// 26587103
// 21508763
// 21058763
// 210 3 8765
// 8765
// 8567 pivot=7
// 6587
// 65 7 8 ..
// 210 3 65 7 8 ..
// 01235678

// median of three ? 

// Stable
// Time Complexity: BC- O(nlogn) , AC- O(nlogn) , WC- O(n^2)
// Space Complexity: O(logn)

template<class T>
size_t partiton(T* arr, size_t n)
{
    T pivot=arr[n/2];
    size_t l=0;
    size_t h=n-1;

    while(true)
    {
        while(arr[l]<pivot)
        {
            l++;
        }
        while(arr[h]>pivot)
        {
            h--;
        }
        if(arr[l]>arr[h])
        {
            std::swap(arr[l],arr[h]);
        }
        else
        {
            return h;
        }
    }

}

template<class T>
void quickSort(T* arr, size_t n)
{
    if(n<2)
       return;
    size_t indexPivot=partiton(arr,n);
    quickSort(arr,indexPivot);
    quickSort(arr+indexPivot+1,n-indexPivot-1);

}

template<class T>
void print(T* arr, size_t n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}


int main()
{
	int arr[]{ 2,8,5,3,9,4,1,7 };
	quickSort(arr, 8);
	print(arr, 8);
}