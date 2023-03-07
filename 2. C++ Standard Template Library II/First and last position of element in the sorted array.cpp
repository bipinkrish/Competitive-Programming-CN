pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
    int left = 0, right = n - 1;
    int first = -1, last = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            right = mid - 1;
        }
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            left = mid + 1;
        }
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return make_pair(first, last);
}