class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i =0;
        int j =0;
        int h = matrix[0].size();
        int r = matrix.size();
        while(j<h&&i<r&&j>=0&&i>=0){
            if(matrix[i][j]==target)return true;
            if(i==r)return false;
            if(target<matrix[i][j]){
                h=j;
                j--;
            }
            else if(target>matrix[i][j]){
                if(j<h-1)j++;
                else i++;
            }
        }
        return false;

    }
};