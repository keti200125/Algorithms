#include<iostream>

//Divide and Conquer


// 28539417
// 2853 9417
// 28 53 94 17
// 2 8 5 3 9 4 1 7
// 28 35 49 17 -merge
// 2358 1479 -merge
// 12345789 -merge


// Stable
// Time Complexity: BC- O(nlogn) , AC- O(nlogn) , WC- O(nlogn)
// Space Complexity: O(n)

template<class T>
void merge(T* arr1, T* arr2, size_t n1, size_t n2)
{
	T* resArr = new T[n1 + n2];

	size_t resIt = 0;
	size_t arr1It = 0;
	size_t arr2It = 0;

	while (arr1It < n1 && arr2It < n2)
	{
		if (arr1[arr1It] <= arr2[arr2It])
		{
			resArr[resIt++] = arr1[arr1It++];
		}
		else
		{
			resArr[resIt++] = arr2[arr2It++];
		}
	}

	while (arr1It < n1)
	{
		resArr[resIt++] = arr1[arr1It++];
	}

	while (arr2It < n2)
	{
		resArr[resIt++] = arr2[arr2It++];
	}

	for (size_t i = 0; i < n1 + n2; i++)
	{
		arr1[i] = resArr[i];
	}

	delete[] resArr;
}

template<class T>
void mergeSort(T* arr, size_t n)
{
	if (!arr || n < 2)
		return;

	size_t middle = n / 2;

	mergeSort(arr, middle);
	mergeSort(arr + middle, n - middle);

	merge<T>(arr, arr + middle, middle, n - middle);
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
	mergeSort(arr, 8);
	print(arr, 8);
}
