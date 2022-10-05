class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int cursum=0;
        int maxsum=nums[0];
        int n=nums.size();
        
        int cursum2=0;
        int minsum=nums[0];
        int ts=0;
        for(int i=0;i<n;i++)
        {
            ts+=nums[i];
            
            cursum+=nums[i];
            if(maxsum<cursum) maxsum=cursum;
            if(cursum<0) cursum=0;
            
            cursum2+=nums[i];
            if(minsum>cursum2) minsum=cursum2;
            if(cursum2>0) cursum2=0;
            
        }
        if(maxsum<0) return maxsum;
        
        return max(maxsum,ts-minsum);
    }
};