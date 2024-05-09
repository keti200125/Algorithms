#include <iostream>
#include <vector>

// 1)
int queueTask(const std::vector<int>& D, const std::vector<int>& C)
{
    std::vector<int> opt(D.size() + 1, 0);
    opt[0] = 0;
    opt[1] = D[0];
    for (int i = 2; i <= D.size(); i++)
    {
        opt[i] = std::min(opt[i - 1] + D[i - 1], opt[i - 2] + C[i - 2]);
    }

    return opt[D.size()];
}

// 2)

std::pair<int, std::vector<int>> queueTask2(const std::vector<int>& D,const std::vector<int>& C)
{
    std::vector<int> opt(D.size() + 1, 0);
    std::vector<int> J(D.size() + 1, 0);

    opt[0] = 0;
    opt[1] = D[0];
    for (int i = 2; i <= D.size(); i++)
    {
        if (opt[i - 1] + D[i - 1] <= opt[i - 2] + C[i - 2])
        {
            opt[i] = opt[i - 1] + D[i - 1];
            J[i] = i - 1;
        }
        else
        {
            opt[i] = opt[i - 2] + C[i - 2];
            J[i] = i - 2;
        }
    }

    return {opt[D.size()], J}; //
}

int main()
{
}