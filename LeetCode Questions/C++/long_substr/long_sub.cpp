class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        map<char, int> mp;
        int maxm = 0, prev = -1;
        
        for (int i = 0; i < n; i++)
        {
            if (mp.count(str[i]) == 0)
            {
                mp.insert({str[i], i});
            }
            else
            {
                prev = max(prev, mp[str[i]]);
                mp[str[i]] = i;
            }
            maxm = max(maxm, i - prev);
        }
        return maxm;
    }
};