class Solution {
public:
    int check(vector<int>& nums, int& sum, int idx, int count,vector<vector<int>> &dp) {
        if (sum == count)
            return 0;
        if (idx >= nums.size() || count > sum) {
            return INT_MAX;
        }
        if(dp[idx][count]!=-1)return dp[idx][count];
        int ans = INT_MAX;
        int r = nums[idx];
        ans = min(check(nums, sum, idx + 1, count + nums[idx],dp), ans);
        int q = 0;
        while (true) {
            q++;
            r /= 2;
            int k = check(nums, sum, idx + 1, count + r,dp);
            if(k!=INT_MAX)ans = min(k + q, ans);
            if (!r)
                break;
        }
        q = 0;
        r = nums[idx];
        while (true) {
            q++;
            r *= 2;
            if (r > sum)
                break;
            int k = check(nums, sum, idx + 1, count + r,dp);
            if(k!=INT_MAX)ans = min(k + q, ans);
        }
        int k= check(nums, sum, idx + 1, count,dp );
        ans = min(ans,k);
        return dp[idx][count]=ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        int mini = INT_MAX;
        vector<vector<int>> dp(nums.size(),vector<int> (sum,-1));
        for (int i = 0; i < nums.size(); i++) {
            mini = min(check(nums, sum, i, 0,dp), mini);
        }
        if (mini == INT_MAX)
            return -1;
        return mini;
    }
};