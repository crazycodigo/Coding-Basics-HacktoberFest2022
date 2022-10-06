class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int> m;
        int l= 0, ans = 0;
        
        for(int i = 0; i<s.length() ; i++){
            if(m.find(s[i])!=m.end()){
                l = max(l,m[s[i]]+1);
            }
            m[s[i]] = i;
            ans = max(ans,i-l+1);
        }
        
        return ans;
    }
};