class Solution {
public:
    int dp[31][100000]={-1};
    int solve(int ind,int sum,int target,int n,int k){
        if(ind>=n){
            if(sum==target) return 1;
            else return 0;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        int ans=0;
        for(int i=1;i<=k;i++){
            ans+=solve(ind+1,sum+i,target,n,k);
            ans%=(1000000007);
        }
        dp[ind][sum]=ans%(1000000007);
        return dp[ind][sum];
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,target,n,k)%(1000000007);
    }
};
