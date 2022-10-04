// Time: 14 ms (41.02%), Space: 18.9 MB (56.01%)

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

    int dfs(TreeNode* root)
    {
        if(root == NULL) return 0;
        int ans = 1;
        if(root->left != NULL)
        {
            ans = max(ans, 1 + dfs(root->left));
        }
        if(root->right != NULL)
        {
            ans = max(ans, 1 + dfs(root->right));
        }
        return ans;
    }
    public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }
};