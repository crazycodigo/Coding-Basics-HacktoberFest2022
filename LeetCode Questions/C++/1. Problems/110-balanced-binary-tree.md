### Balanced Binary Tree
**Question Link: https://leetcode.com/problems/balanced-binary-tree/**
```
class Solution {
public:
    int solveHeight(TreeNode *root ){
        if(root == NULL)
            return true ;
        
        int hLeft = solveHeight(root->left) ;
        if(hLeft == -1) return -1 ;
        
        int hRight = solveHeight(root->right) ;
        if(hRight == -1) return -1 ;
        
        if(abs(hRight - hLeft) > 1) return -1 ;
        return 1 + max(hRight , hLeft) ;
    }
    bool isBalanced(TreeNode* root) {
        return (solveHeight(root) != -1) ;
    }
};
```
