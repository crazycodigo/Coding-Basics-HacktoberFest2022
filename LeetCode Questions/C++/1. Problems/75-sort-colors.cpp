class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cn0,cn1,cn2;
        cn0=cn1=cn2=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
                cn0++;
            else if(nums[i]==1)
                cn1++;
            else
                cn2++;
        }
        int k = 0;
        for(int i=0; i<cn0; i++){
            nums[k]=0;
            k++;
        }
        
        for(int i=0; i<cn1; i++){
            nums[k]=1;
            k++;
        }
        
        for(int i=0; i<cn2; i++){
            nums[k]=2;
            k++;
        }
    }
};