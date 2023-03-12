#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseString(string str)
{
    stringstream ss(str);
    vector<string> words;
    string word;
    while (ss >> word)
    {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
    stringstream result;
    for (const auto &w : words)
    {
        result << w << " ";
    }
    return result.str();
}

// python code
// def reverseString(str):
// 	return " ".join(x for x in str.split()[::-1])
