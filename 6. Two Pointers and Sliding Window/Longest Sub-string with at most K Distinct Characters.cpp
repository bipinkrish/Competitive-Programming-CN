#include <unordered_map>

int getLengthofLongestSubstring(int k, string s)
{
    int n = s.length();
    int left = 0, right = 0;
    int max_len = 0;
    unordered_map<char, int> char_count;
    while (right < n)
    {
        char_count[s[right]]++;
        while (char_count.size() > k)
        {
            char_count[s[left]]--;
            if (char_count[s[left]] == 0)
            {
                char_count.erase(s[left]);
            }
            left++;
        }
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}
