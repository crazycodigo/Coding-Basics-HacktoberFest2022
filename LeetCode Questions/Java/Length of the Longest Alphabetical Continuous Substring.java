/*

https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/

*/
class Solution {
    public int longestContinuousSubstring(String s) {
        
        int ans=1, curr=1,i;
        for(i=1; i<s.length(); i++)
        {
            char prevchar=s.charAt(i-1); char currchar=s.charAt(i);
            if(prevchar+1==currchar)
            {
                curr++;
                
            }
            else
                curr=1;
            ans=Math.max(ans, curr);
        }
        return ans;
        
    }
}
