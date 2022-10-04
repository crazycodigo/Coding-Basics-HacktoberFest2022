class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
                    sort(potions.begin(),potions.end());
        for(int i = 0; i<spells.size() ; i++){
            int c=0;

            int s = 0, e = potions.size()-1;
            // for(int j =0; j<potions.size(); j++){
            //     long long t = ll(potions[j])*ll(spells[i]);
            //     if(t>=success)
            //         c++;
            // }
            //cout<<i<<endl;
            int a = -1;
            while(s<=e){
                int m = (s+e)/2;
                long long t = ll(potions[m])*ll(spells[i]);
                if(t<success){
                    s = m+1;
                }
                if(t>=success){
                    e = m-1;
                    a = m;
                }
            }
           // if(m)
            if(a==-1)
                ans.push_back(0);
            else
                ans.push_back(potions.size()-a);
        }
        
        return ans;
    }
};