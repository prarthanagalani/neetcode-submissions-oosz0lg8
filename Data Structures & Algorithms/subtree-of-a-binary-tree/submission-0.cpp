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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(subRoot == NULL) return true;

        if(root == NULL) return false;

        if(isidentical(root,subRoot)) return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }

    bool isidentical(TreeNode* a, TreeNode* b){

        if(!a && !b) return true;

        if(!a || !b) return false;

        return (a->val == b->val) && isidentical(a->left,b->left) && isidentical(a->right,b->right);
    }
};