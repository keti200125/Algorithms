#include<iostream>
#include<vector>
#include <algorithm>




// <3 , 5, 2, 8, 4>
// k=3


std::vector<std::vector<int>> findSum(const std::vector<int>& alpha, size_t k)
{
	size_t n = alpha.size();
	std::vector<std::vector<int>> dp(k, std::vector<int>(n, 1000));
	dp[0][0] = alpha[0];
	for (int i = 1; i < n; i++)
	{
		dp[0][i] = dp[0][i - 1] + alpha[i];
	}

	for (int i = 1; i < k; i++) // zapochvame ot red 2
	{
		for (int j = i; j < n; j++) 
		{
			for (int m =i-1; m <n; m++) 
			{
				dp[i][j] = std::min(dp[i][j],std::max(dp[i - 1][m], dp[0][j] - dp[0][m]));
			}
		}
	}
	return dp;
	//return dp[k-1][n-1];
}

int main()
{
	std::vector<int> alpha = { 5,6,3,8,1};
	//std::vector<int> alpha = { 7, 2, 5, 10, 8, 3, 6, 7, 8, 9, 8, 2, 3, 4, 7, 8, 9, 2, 3, 4, 7, 2, 6, 7, 3, 5, 6, 1, 5, 10, 4 };
	
	int k = 3;
	//int n = 5;

	//int n = 5;  // Number of rows
	//int k = 3;  // Number of columns

	// Initializing the vector with -1
	//std::vector<std::vector<int>> myVector(n, std::vector<int>(k, 0));

	//std::vector<std::vector<int>> dp= findSum(nums, k, n);

	std::vector<std::vector<int>> dp = findSum(alpha, k);
	///std::cout<<findSum(alpha, k);
	//}




//	725 108 367 89   823



	for (const auto& part :dp) {
		for (int num : part) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}

	//std::vector<std::vector<int>> partitions = getPartitions(nums, k);

	/*
	for (const auto& partition : partitions) {
		for (int num : partition) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}


	*/
	return 0;

}