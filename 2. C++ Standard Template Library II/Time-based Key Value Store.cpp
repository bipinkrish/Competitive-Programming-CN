#include <map>
#include <string>
#include <vector>

class Timebased
{
public:
    map<string, map<int, string, greater<int>>> mp;

    void setKey(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string getValue(string key, int timestamp)
    {
        if (mp.count(key) == 0)
            return "-1";

        auto itr = mp[key].lower_bound(timestamp);
        if (itr == mp[key].end())
            return "-1";
        return itr->second;
    }
};