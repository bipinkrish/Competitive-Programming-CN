#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

double dist(pii x, pii y)
{
    int dx = x.first - y.first;
    int dy = x.second - y.second;
    return sqrt(dx * dx + dy * dy);
}

bool cmp(pii x, pii y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
}

double closestPairUtil(pii *a, int n)
{
    if (n <= 3)
    {
        double ans = 10000;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = min(ans, dist(a[i], a[j]));
            }
        }
        return ans;
    }
    int mid = n / 2;
    pii midPoint = a[mid];
    double dl = closestPairUtil(a, mid);
    double dr = closestPairUtil(a + mid, n - mid);
    double d = min(dl, dr);
    vector<pii> strip;
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i].first - midPoint.first) < d)
        {
            strip.push_back(a[i]);
        }
    }
    sort(strip.begin(), strip.end(),
         [](pii x, pii y)
         { return x.second < y.second; });
    int m = strip.size();
    double ans = d;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m && strip[j].second - strip[i].second < d; j++)
        {
            ans = min(ans, dist(strip[i], strip[j]));
        }
    }
    return ans;
}

long closestPair(pair<int, int> *coordinates, int n)
{
    vector<pii> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back({coordinates[i].first, coordinates[i].second});
    }
    sort(a.begin(), a.end(), cmp);
    return (long)(closestPairUtil(a.data(), n) * closestPairUtil(a.data(), n) +
                  0.5);
}