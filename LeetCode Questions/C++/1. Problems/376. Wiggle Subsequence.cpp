class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         int length = 1;
       int flag = -1;
        for(int i=1;i<nums.size();i++){
            if(flag ==-1) {
                if(nums[i]==nums[i-1]) continue;
                if(nums[i]-nums[i-1]>0) flag = true;
                else flag = false;
                length++;
            }
            else if(flag == true && nums[i]-nums[i-1]<0){
                length++;
                flag = false;
            }
            else if(flag ==false && nums[i]-nums[i-1]>0){
                length++;
                flag =true;
            }
        }
    return length;
    }
};