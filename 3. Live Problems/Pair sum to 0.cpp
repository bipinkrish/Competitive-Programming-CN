#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n)
{
    int count = 0;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        if (freq.find(arr[i]) != freq.end())
        {
            freq[arr[i]] += 1;
        }
        else
        {
            freq[arr[i]] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int comp = -arr[i];
        if (freq.find(comp) != freq.end())
        {
            count += freq[comp];
            if (comp == arr[i])
            {
                count -= 1;
            }
        }
    }

    return count / 2;
}
