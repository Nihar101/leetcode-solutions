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
    int ans=0;
    int check(TreeNode* root){
        if(!root)return 0;
        int a = check(root->left);
        int b = check(root->right);
        ans+= abs(a-b);
        return a+b+root->val;
    }
    int findTilt(TreeNode* root) {
        check(root);
        return ans;
    }
};