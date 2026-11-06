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
    vector<TreeNode*> check(int a,int b){
        if(a>b)return {nullptr};
        vector<TreeNode*> ans;
        for(int i=a;i<=b;i++){
            
            vector<TreeNode*> left = check(a,i-1);
            vector<TreeNode*> right = check(i+1,b);
            for(int j=0;j<left.size();j++){
                
                for(int k=0;k<right.size();k++){
                    TreeNode* curr = new TreeNode(i);
                    curr->left= left[j];
                    curr->right = right[k];
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        TreeNode * root = new TreeNode(-1);
        return check(1,n);
    }
};