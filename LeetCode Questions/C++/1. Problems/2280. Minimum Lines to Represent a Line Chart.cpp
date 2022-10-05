class Solution {
public:
    static bool sortvec(const vector<int>& v1, const vector<int>& v2){
        return v1[0] < v2[0];
    }
    
    int minimumLines(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), sortvec);
        long n = arr.size();
        if(n<=1)
            return 0;
        long count = 1;
        pair<int,int> prev;
        int num = arr[1][1]-arr[0][1];
        int dum = arr[1][0] - arr[0][0];
        int g = __gcd(num,dum);
        num = num/g;
        dum = dum/g;
        prev.first = num;
        prev.second = dum;
        for(long i = 2;i < n; i++){
            pair<int,int> curr;
            
            num = arr[i][1]-arr[i-1][1];
            dum = arr[i][0]-arr[i-1][0];
            g = __gcd(num,dum);
            num = num/g;
            dum = dum/g;
            
            curr.first = num;
            curr.second = dum;

            if(curr==prev)
                continue;
            prev = curr;
            count++;
        }
        
        
        return count;
    }
};