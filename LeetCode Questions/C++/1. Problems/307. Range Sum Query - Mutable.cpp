class NumArray {
public:
    vector<int> arr;
    int sum = 0;
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            arr.push_back(nums[i]);
            sum += nums[i]; 
        }
    }
    
    void update(int index, int val) {
        sum += (val - arr[index]);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        if(right-left < arr.size()/2){
            ans = accumulate(arr.begin()+left, arr.begin()+right+1, 0);
        }
        else{
            ans = sum - accumulate(arr.begin(), arr.begin()+left, 0) - accumulate(arr.begin()+right+1,arr.end(), 0);
        }
        
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */