class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> answer;
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(map.find(temp) != map.end()){
                answer.push_back(map[temp]);
                answer.push_back(i);
                break;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return answer;
        
    }
};