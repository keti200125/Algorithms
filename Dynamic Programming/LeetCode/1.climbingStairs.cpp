#include <iostream>
#include <vector>

int climbStairs(int n)
{
    std::vector<int> v(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    return v[n];
}
