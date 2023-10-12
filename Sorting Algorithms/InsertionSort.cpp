#include<iostream>
 
// 2 8 5 3 9 4
// 2 8 5 3 9 4
// 2 5 8 3 9 4
// 2 3 5 8 9 4
// 2 3 4 5 8 9

// Stable
// Time Complexity: BC- O(n) , AC- O(n^2) , WC- O(n^2)
// Space Complexity:O(1)

template<class T>
void insertionSort(T* arr,size_t n)
{
	for (int i = 1; i < n; i++)
	{
		T elem = arr[i]; 
		int j = i-1;

		while (elem < arr[j] && j >= 0)  
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = elem;
	}

}


template<class T>
void print(T* arr, size_t n)
{
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
}


int main()
{
	int arr[]{8,2,5,3,9,4};
	insertionSort(arr, 6);
	print(arr, 6);
}
