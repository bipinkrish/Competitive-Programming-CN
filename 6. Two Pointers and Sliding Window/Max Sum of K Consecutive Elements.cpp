#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> subarrays;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            subarrays.push_back(sum);
        }
    }
    sort(subarrays.rbegin(), subarrays.rend());
    return subarrays[k - 1];
}
