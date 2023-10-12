#include<iostream>

// 2 8 5 3 9 4 1
// 1 8 5 3 9 4 2
// 1 2 5 3 9 4 8
// 1 2 3 5 9 4 8
// 1 2 3 4 9 5 8
// 1 2 3 4 5 9 8
// 1 2 3 4 5 8 9

// Stable
// Time Complexity: BC- O(n^2) , AC- O(n^2) , WC- O(n^2)
// Space Complexity: O(1)

template<class T>
void selectionSort(T* arr, size_t n)
{
	for (size_t i = 0; i < n - 1; i++)
	{
		size_t minIndex = i;
		for (size_t j = i+1; j < n; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			std::swap(arr[minIndex], arr[i]);
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
	selectionSort(arr, 7);
	print(arr, 7);
}



