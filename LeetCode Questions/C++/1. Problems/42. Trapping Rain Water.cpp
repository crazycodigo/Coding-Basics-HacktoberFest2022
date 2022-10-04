class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int l[n],r[n];
        
        for(int i = 0; i<n; i++){
            if(i==0)
                l[i] = height[i];
            else{
                if(height[i]>l[i-1])
                    l[i] = height[i];
                else
                    l[i] = l [i-1];
            }
        }
        
        
        for(int i = n-1; i>=0; i--){
            if(i==n-1)
                r[n-1] = height[i];
            else{
                if(height[i]>r[i+1])
                    r[i] = height[i];
                else
                    r[i] = r[i+1];
            }
        }
        
        int ans = 0;
        for(int i = 0; i<n  ; i++){
            cout<<l[i]<<" "<<r[i]<<endl;
            ans += min(l[i],r[i])-height[i];
        }
        
        return ans;
    }
};