#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int max_area = 0;
    while (left < right)
    {
        int area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, area);
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_area;
}
