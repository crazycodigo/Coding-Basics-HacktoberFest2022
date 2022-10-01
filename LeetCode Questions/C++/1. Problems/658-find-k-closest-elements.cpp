class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int s = 0; 
        int e= arr.size()-1;
        while(e-s>=k){
            if(x-arr[s]<=arr[e]-x)
                e--;
            else
                s++;
        }
        
        for(int i=s; i<=e; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};