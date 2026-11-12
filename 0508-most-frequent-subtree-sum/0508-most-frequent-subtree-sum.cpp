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
    int check(TreeNode* root){
        if(!root)return 0;
        int l =check(root->left);
        int r =check(root->right);
        m[root->val+l+r]++;
        return root->val+l+r;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
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