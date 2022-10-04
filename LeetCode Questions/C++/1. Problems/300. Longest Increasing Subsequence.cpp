class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp (nums.size(),1);
        int n = nums.size();
        int i =1, j=0;
        while(i<n){
            j = 0;
            while(j<i){
                if(nums[i]>nums[j])
                    temp[i] = max(temp[i],temp[j]+1);
                j++;
            }
            i++;
        }
        int ans = 0;
        for(int i = 0; i<n; i++)
            ans = max(ans,temp[i]);
        
        return ans;
    }
};