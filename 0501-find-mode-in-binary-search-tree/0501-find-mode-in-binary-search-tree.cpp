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
    unordered_map<int,int> m;
    void check(TreeNode* root){
        if(!root)return;
        m[root->val]++;
        check(root->left);
        check(root->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        check(root);
        int maxi=0;
        for(auto x:m){
            maxi=max(x.second,maxi);
        }
        for(auto x:m){
            if(x.second==maxi)ans.push_back(x.first);
        }
        return ans;
    }
};