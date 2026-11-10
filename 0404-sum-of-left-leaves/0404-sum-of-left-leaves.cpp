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
    int count=0;
    void search(TreeNode* root){
        if(!root)return;
        if(root->left&&!root->left->right&&!root->left->left)count+=root->left->val;
        if(root->left)search(root->left);
        if(root->right)search(root->right);
        return ;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        search(root);
        return count; 
    }
};