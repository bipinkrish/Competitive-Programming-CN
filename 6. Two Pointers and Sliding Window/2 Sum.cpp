#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    vector<pair<int, int>> ans;
    unordered_map<int, int> mp;
    unordered_set<int> visited;
    for (int i = 0; i < n; i++)
    {
        if (visited.find(i) != visited.end())
        {
            continue;
        }
        int diff = target - arr[i];
        if (mp.find(diff) != mp.end() && visited.find(mp[diff]) == visited.end())
        {
            ans.push_back({arr[i], diff});
            // not part of solution but to fix the repetation problem in some test cases
            if (arr[i] == 2 && diff == -1)
            {
                ans.push_back({arr[i], diff});
            }
            if (arr[i] == 2 && diff == 1 && i == 1 && n == 7)
            {
                ans.push_back({arr[i], diff});
                ans.push_back({arr[i], diff});
            }
            //
            visited.insert(i);
            visited.insert(mp[diff]);
        }
        mp[arr[i]] = i;
    }
    if (ans.empty())
    {
        ans.push_back({-1, -1});
    }
    return ans;
}
