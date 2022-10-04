//  Time: 374 ms (32.20%), Space: 146.4 MB (8.78%)

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
    int mindepth(TreeNode* root)
    {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int ans = 1e9;
        if(root->left != NULL)
        {
            ans = min(ans, 1 + mindepth(root->left));
        }
        if(root->right != NULL)
        {
            ans = min(ans, 1 + mindepth(root->right));
        }
        return ans;
    }
    
    int minDepth(TreeNode* root) {
        return mindepth(root);
    }
};