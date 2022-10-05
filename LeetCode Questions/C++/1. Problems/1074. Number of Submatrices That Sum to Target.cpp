class Solution {
public:
    int f(vector<int> & v,int t){
        int n=v.size(),sum=0,ans=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(m.count(sum-t))ans+=m[sum-t];
            m[sum]++;
        }
        return ans;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& v, int t) {
        if(v.size()==0)return 0;
        int n=v.size(),m=v[0].size(),ans=0;
        for(int j=0;j<m;j++){
            vector<int>a(n,0);
            for(int k=j;k<m;k++){
                for(int i=0;i<n;i++)a[i]+=v[i][k];
                ans+=f(a,t);
            }
        }
        return ans;
    }
};