class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i=0;i<grid.size();i++){
            int k = rowShift[i];
            vector<int> ans(grid[0].size());
            for(int j=0;j<grid[0].size();j++){
                ans[(j-k+n)%n]=grid[i][j];
            }
            grid[i] = ans;
        }
        for(int j=0;j<grid[0].size();j++){
            int k = colShift[j];
            vector<int> ans(grid.size());
            for(int i=0;i<grid.size();i++){
                ans[(i-k+n)%n]= grid[i][j];
            }
            for(int i=0;i<grid.size();i++){
                grid[i][j]= ans[i];
            }
        }
        return grid;
    }
};