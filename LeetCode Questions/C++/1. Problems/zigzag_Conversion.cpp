class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        vector <string> tmp(numRows);                                                         
        //create strings for each row
        int i=0, n=s.size();
        while(i<n){                                      
            for(int j=0;j<numRows && i<n; j++, i++) tmp[j] += s[i];              
            //add for our strings character when we move down
            for(int j=numRows - 2;j>0 && i<n; j--, i++) tmp[j] += s[i];
            //add for our strings character when we move up exept first and last string
        }
        for(int j=0;j<numRows; j++) ans += tmp[j];                    
        //combain together our strings
        return ans;
    }
};