#include <algorithm>
#include <utility>
#include <vector>

int maxLengthChain(std::vector<std::pair<int, int>> &p, int n)
{
    std::sort(p.begin(), p.end(),
              [](std::pair<int, int> a, std::pair<int, int> b)
              {
                  return a.second < b.second;
              });

    int end = p[0].second;
    int max_length = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i].first > end)
        {
            end = p[i].second;
            max_length++;
        }
    }

    return max_length;
}
