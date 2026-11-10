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
     TreeNode * l =NULL;
    TreeNode * r = NULL;
    TreeNode* prev=NULL;
    void leftsearch(TreeNode* root){
        if(!root)return ;
        if(root->left)leftsearch(root->left);
        if(prev!=NULL&&prev->val>root->val&&!l)l=prev;
        prev=root;
        if(root->right)leftsearch(root->right);
        return ;
    }
    void rightsearch(TreeNode* root){
        if(!root) return ;
        if(root->right)rightsearch(root->right);
        if(prev!=NULL&&prev->val<root->val&&!r)r=prev;
        prev=root;
        if(root->left)rightsearch(root->left);
        return ;
    }
    void recoverTree(TreeNode* root) {
        prev=NULL;
        leftsearch(root);
        prev=NULL;
        rightsearch(root);
        swap(l->val,r->val);
        return ;
    }
};