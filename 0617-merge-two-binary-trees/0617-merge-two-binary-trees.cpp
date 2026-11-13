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
    TreeNode* check(TreeNode* root1,TreeNode* root2){
        if(!root1&&!root2)return NULL;
        int a= 0;
        if(root1)a=root1->val;
        int b = 0;
        if(root2)b=root2->val;
        TreeNode* curr = new TreeNode(b+a);
        curr->left = check(root1?root1->left:NULL,root2?root2->left:NULL);
        curr->right = check(root1?root1->right:NULL,root2?root2->right:NULL);
        return curr;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       return check(root1,root2);

    }
};