#include <iostream>
#include <vector>

int fibonacci(int n)
{
    std::vector<int> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}