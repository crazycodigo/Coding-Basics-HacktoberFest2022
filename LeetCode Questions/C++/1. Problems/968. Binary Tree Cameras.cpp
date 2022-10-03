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
    int minCameraCover(TreeNode* root) {
        int noOfCam = 0;
        int ans = helper(root, noOfCam);
        
        if(ans == -1)   //we need to fix a camera
            noOfCam++;
        
        return noOfCam;
    }
    
    int helper(TreeNode* root, int &noOfCam){
        if(root== NULL) 
            return 1;
        
        int left = helper(root->left, noOfCam);
        int right = helper(root->right, noOfCam);
        

        if(left==-1 || right==-1){
            noOfCam++;
            return 0;   
        }
        
        if(left==0 || right==0)
            return 1;
        return -1;
        
    }
};