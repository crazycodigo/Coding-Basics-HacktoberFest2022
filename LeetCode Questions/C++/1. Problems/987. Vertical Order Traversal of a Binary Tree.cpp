/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, map<int,map<int,vector<int>>> &m, int currX = 0, int currY = 0){
        if(root==NULL)
            return;
        m[currX][currY].push_back(root->val);
        
        helper(root->left,m,currX-1,currY+1);
        helper(root->right,m,currX+1, currY+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> m;
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        
        helper(root,m);

        for(auto it = m.begin(); it!=m.end(); it++){
            map<int,vector<int>> r = it->second;
            vector<int> temp;
            for(auto i2t = r.begin() ; i2t != r.end() ; i2t++){
                vector<int> x = i2t->second;
                sort(x.begin(),x.end());
                
                temp.insert(temp.end(), x.begin(), x.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};