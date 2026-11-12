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
    vector<int> ans;
    void check(TreeNode* root){
        if(!root)return;
        check(root->right);
        ans.push_back(root->val);
        check(root->left);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        check(root);
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,abs(ans[i]-ans[i+1]));
        }
        return mini;
    }
};