#include <unordered_map>
#include <vector>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> map;
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        map[arr[i]] = true;
    }

    int maxlength = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]])
        {
            int length = 0;
            int temp = arr[i];
            while (map.count(temp))
            {
                length++;
                map[temp] = false;
                temp = temp + 1;
            }
            int starttemp = arr[i];
            temp = arr[i] - 1;
            while (map.count(temp))
            {
                length++;
                map[temp] = false;
                starttemp = temp;
                temp = temp - 1;
            }

            if (length > maxlength)
            {
                maxlength = length;
                start = starttemp;
            }
            else if (length == maxlength)
            {
                maxlength = length;
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == start)
                    {
                        start = start;
                        break;
                    }
                    else if (arr[j] == starttemp)
                    {
                        start = starttemp;
                        break;
                    }
                }
            }
        }
    }

    output.push_back(start);
    output.push_back(start + maxlength - 1);

    return output;
}
