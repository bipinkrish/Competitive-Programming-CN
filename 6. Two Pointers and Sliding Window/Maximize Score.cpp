int maximizeScore(vector<int> &arr, int n, int k)
{
    int sum = 0;

    // Calculate sum of array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int minSum = sum;
    // Find subarray of size N - K having minimum sum
    for (int i = 0; i <= k; i++)
    {
        int cur = 0;
        for (int j = i; j < i + n - k; j++)
        {
            cur += arr[j];
        }
        // Update minSum
        minSum = min(minSum, cur);
    }
    return sum - minSum;
}