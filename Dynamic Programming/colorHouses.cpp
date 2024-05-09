#include <iostream>
#include <vector>

int colorHouses(const std::vector<int> &cRed,
const std::vector<int> &cGreen,
const std::vector<int> &cBlue)
{
    int n = cRed.size();
    std::vector<int> optRed(n, cRed[0]);
    std::vector<int> optGreen(n, cGreen[0]);
    std::vector<int> optBlue(n, cBlue[0]);

    for (int i = 1; i < cRed.size(); i++)
    {
        optRed[i] = cRed[i] + std::min(optBlue[i - 1], optGreen[i - 1]);
        optGreen[i] = cGreen[i] + std::min(optBlue[i - 1], optRed[i - 1]);
        optBlue[i] = cBlue[i] + std::min(optRed[i - 1], optGreen[i - 1]);
    }

    return std::min(optRed[n - 1], optGreen[n - 1], optBlue[n - 1]);
}