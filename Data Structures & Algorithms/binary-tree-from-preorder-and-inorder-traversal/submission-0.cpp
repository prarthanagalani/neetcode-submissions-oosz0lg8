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
    
    TreeNode* f(int prestart, int preend, int instart, int inend, vector<int>&inorder, vector<int>&preorder, unordered_map<int,int>&mp){

        if(prestart > preend || instart > inend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int val = root->val;

        int inorder_idx = mp[val];

        int leftele = inorder_idx - instart;

        root->left = f(prestart+1,prestart+leftele,instart,inorder_idx-1,inorder,preorder,mp);
        root->right = f(prestart+leftele+1,preend,inorder_idx+1,inend,inorder,preorder,mp);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();

        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }


        return f(0,n-1,0,n-1,inorder,preorder,mp);
        
    }
};