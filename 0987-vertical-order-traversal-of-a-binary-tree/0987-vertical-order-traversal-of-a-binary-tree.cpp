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
    map<TreeNode*,pair<int,int>> m;
    int mini =0;
    int maxi=0;
    void verify(TreeNode* root,int c){
        if(root->left){
            c--;
            mini = min(c,mini);
            verify(root->left,c);
            c++;
        }
        if(root->right){
            c++;
            verify(root->right,c);
            maxi = max(maxi,c);
            c--;
        }
        return;
    }
    void check(TreeNode* root,int r,int c){
        m[root]={r,c};
        if(root->left)check(root->left,r+1,c-1);
        if(root->right)check(root->right,r+1,c+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)return {};
        verify(root,0);
        int n = maxi-mini+1;
        vector<vector<pair<TreeNode*,int>>> ans(n);
        check(root,0,0);
        mini = abs(mini);
        map<TreeNode*,int> rowp;
        for(auto x: m){
            int val = x.first->val;
            int r = x.second.first;
            int c= x.second.second;
            rowp[x.first]=r;
            ans[c+mini].push_back({x.first,val});
        }
        
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end(),[&rowp](pair<TreeNode* ,int>a,pair<TreeNode*,int>b){
                if(rowp[a.first]<rowp[b.first])return true;
                else if(rowp[a.first]==rowp[b.first]){
                    return a.second<b.second;
                }
                return false;
            });
        }
        vector<vector<int>> secondans(n);
        for(int i =0;i<n;i++){
            for(int j = 0;j<ans[i].size();j++){
               secondans[i].push_back(ans[i][j].second);
            }
        }
        return secondans;
    }
};