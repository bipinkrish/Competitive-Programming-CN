bool CheckSumPairs(int ar[], int n, int k, int m)
{
    // Hashmap to store remainder frequencies
    unordered_map<int, int> remainderCount;
    // Iterate through the array and store remainder frequencies
    for (int i = 0; i < n; i++)
    {
        int remainder = ar[i] % k;
        remainderCount[remainder]++;
    }
    // Iterate through the remainders and check for pairs
    for (auto it : remainderCount)
    {
        int remainder = it.first;
        int count = it.second;
        // Check if there is another remainder that can form a pair
        int pairRemainder = (m - remainder) % k;
        if (pairRemainder < 0)
        {
            pairRemainder += k;
        }
        if (remainderCount.find(pairRemainder) != remainderCount.end())
        {
            // Check if there are enough elements to form pairs
            if (remainder == pairRemainder)
            {
                if (count % 2 != 0)
                {
                    return false;
                }
            }
            else if (count != remainderCount[pairRemainder])
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
