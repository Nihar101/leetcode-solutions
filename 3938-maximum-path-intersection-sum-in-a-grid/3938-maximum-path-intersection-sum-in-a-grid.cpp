class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> pre(n,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j]= grid[i][j-1]+ pre[i][j-1];
            }
            int idx =-1;
            int mini =INT_MAX;
            int mini2=INT_MAX;                       // NEW: second minimum
            for(int j=0;j<=m;j++){
                if(idx!=-1){                         // CHANGED: replaces your old condition
                    // segment = cells idx..j-1, single cell when idx==j-1
                    bool bad = (idx==j-1) && (i==0||i==n-1||idx==0||idx==m-1);
                    if(!bad) ans = max(ans,pre[i][j]-mini);
                    else if(mini2!=INT_MAX) ans = max(ans,pre[i][j]-mini2);
                }
                if(mini>pre[i][j]){                  // CHANGED: keep second min
                    mini2=mini;
                    idx= j;
                    mini = pre[i][j];
                }
                else if(mini2>pre[i][j]) mini2=pre[i][j];
            }
        }
        vector<vector<int>> cre(n+1,vector<int> (m,0));
        for(int j=0;j<m;j++){
            for(int i=1;i<=n;i++){
                cre[i][j]= cre[i-1][j]+ grid[i-1][j];
            }
            int idx=-1;
            int mini = INT_MAX;
            int mini2 = INT_MAX;
            for(int i=0;i<=n;i++){
                if(idx!=-1){
                    // segment = rows idx..i-1 in column j
                    bool bad = (idx==i-1) && (j==0||j==m-1||idx==0||idx==n-1);
                    if(!bad) ans = max(ans,cre[i][j]-mini);
                    else if(mini2!=INT_MAX) ans = max(ans,cre[i][j]-mini2);
                }
                if(mini>cre[i][j]){
                    mini2=mini;
                    idx=i;
                    mini=cre[i][j];
                }
                else if(mini2>cre[i][j]) mini2=cre[i][j];
            }
        }
        return ans;
    }
};