class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, l = nums.size()-1,m = 0;
        //cout<<s<<l;
        while(s<=l){
            m = (s+l)/2;
           // cout<<m<<endl;
            if(nums[m]>target)
                l = m-1;
            else if(nums[m]<target)
                s = m+1;
            else
                return m;
        }
        return l;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        map<int,int> m ;
        for(int i = 0; i<n ; i++){
            int price = items[i][0];
            int beauty = items[i][1];
            if(m[price]==0)
                m[price] = beauty;
            else if(m[price]<beauty)
                m[price] = beauty;
        }
        
        int max = 0;
        for(auto it = m.begin() ; it!= m.end() ; it++){
            if(it->second > max)
                max = it->second;
            else
                it->second = max;
        }
        
        vector<int> ans;
        
        int first = m.begin()->first;
        auto it=m.end();
        it--;
        int last=it->first;
        int prev = m.begin()->second;
        
        
        vector<int> prices ;
        vector<int> beauties;
        for(auto it:m){
            prices.push_back(it.first);
            beauties.push_back(it.second);
        }
        
        for(int i = 0; i< queries.size(); i++){
            int p = queries[i];
            if(p<first)
                ans.push_back(0);
            else if(p>=last)
                ans.push_back(m[last]);
            else{
                int pos = search(prices,p);
                ans.push_back(beauties[pos]);                       
            }
        }
        
        return ans;
    }
};