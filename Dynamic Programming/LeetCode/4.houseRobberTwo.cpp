#include <iostream>
#include <vector>

int houseRobber(const std::vector<int> &nums, int start)
{
    int n = nums.size();
    if (n == 2)
        return nums[start];

    std::vector<int> dp(n - 1);
    dp[0] = nums[start];
    dp[1] = std::max(nums[start], nums[start + 1]);
    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[start + i]);
    }
    return dp[n - 2];
}

int rob(const std::vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    return std::max(houseRobber(nums, 0), houseRobber(nums, 1));
}
