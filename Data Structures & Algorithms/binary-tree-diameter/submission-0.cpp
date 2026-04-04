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
    
    int f(TreeNode* root, int &ans){

        if(!root) return 0;

        int lh = f(root->left,ans);
        int rh = f(root->right,ans);

        ans = max(ans,lh+rh);

        return 1+max(lh,rh);


    }

    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;

        f(root,d);

        return d;


        
    }
};
