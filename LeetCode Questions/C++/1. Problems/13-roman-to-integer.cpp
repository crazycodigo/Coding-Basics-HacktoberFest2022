class Solution {

private: 
    int indexOf(char c, vector<char> sym){
        for(int i=0; i<sym.size(); i++){
            if(sym[i]==c)
                return i;
        }
        return -1;    
    }
public:
    int romanToInt(string s) {        
        vector<char> sym{'I','V','X','L','C','D','M'};
        vector<int> val{1,5,10,50,100,500,1000};
        
        int ans = 0;
        int n = s.length();
        for(int i=0; i<n-1; i++){
            int x = indexOf(s[i], sym);
            int y = indexOf(s[i+1], sym);
            if(val[x]<val[y])
                ans-=val[x];
            else
                ans+=val[x];

        }
        int x = indexOf(s[n-1], sym);
        ans+=val[x];
        
        return ans;
    }
};
