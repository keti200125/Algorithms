#include<iostream>

// 2 8 5 3 9 4 1
// 2 5 8 3 9 4 1
// 2 5 3 8 9 4 1
// 2 5 3 8 4 9 1
// 2 5 3 8 4 1 9
// 2 3 5 8 4 1 9
// 2 3 5 4 8 1 9
// 2 3 4 5 1 8 9 ...

// Stable
// Time Complexity: BC- O(n) , AC- O(n^2) , WC- O(n^2)
// Space Complexity: O(1)

template<class T>
void bubbleSort(T* arr,size_t n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j <n-i-1; j++)
		{
			if (arr[j]> arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
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
	int arr[]{2,8,5,3,9,4,1};
	bubbleSort(arr, 7);
	print(arr, 7);
}