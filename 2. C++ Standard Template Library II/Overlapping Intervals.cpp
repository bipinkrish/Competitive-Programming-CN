#include <iostream>
#include <algorithm>

using namespace std;

bool checkOverlappingIntervals(long *start, long *end, int n)
{
    sort(start, start + n);
    sort(end, end + n);

    int end_ptr = 0;
    for (int start_ptr = 1; start_ptr < n; start_ptr++)
    {
        if (start[start_ptr] < end[end_ptr])
            return true;
        end_ptr++;
    }
    return false;
}
