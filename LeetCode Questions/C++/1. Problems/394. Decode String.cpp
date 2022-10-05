class Solution {
public: 
    string decodeString(string s) {
        stack<string> st; 
        for(auto& c:s){
            if(c==']'){ 
                string temp = "",curr = "";
                while(!st.empty() and st.top()!="["){
                    reverse(st.top().begin(),st.top().end());
                    temp += st.top(); 
                    st.pop();
                }
                st.pop(); 
                string times = ""; 
                while(!st.empty() and st.top()>="0" and st.top()<="9"){
                    times += st.top();
                    st.pop();
                }
                reverse(times.begin(),times.end());
                reverse(temp.begin(),temp.end());
                int k = stoi(times); 
                while(k--)
                    curr += temp;
                if(!st.empty() and st.top()!="[")
                    st.top() += curr;  
                else
                    st.push(curr);
            }
            else{
                string curr = "";
                curr.push_back(c);
                st.push(curr); 
            }
        }
        string ans = ""; 
        while(!st.empty()){
            reverse(st.top().begin(),st.top().end());
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    
};