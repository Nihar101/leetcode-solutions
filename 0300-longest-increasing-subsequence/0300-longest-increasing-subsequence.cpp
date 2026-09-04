class Solution {
public:
    int check(int i,vector<int> &dp,vector<int>&nums,int x){
        if(i==-1)return 0;
        int k = check(i-1,dp,nums,x);
        if(dp[i]!=-1&&(x>nums[i]||x==-100000))return max(dp[i],k);
        if(x>nums[i]||x==-100000){
            int l =  1 + check(i-1,dp,nums,nums[i]);
            dp[i]= l;
            return max(dp[i],k);
        }
        return k;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        check(nums.size()-1,dp,nums,-100000);
        int maxi =0;
        for(int i =0;i<nums.size();i++){
           maxi= max(maxi,dp[i]);
        }
        return maxi;
    }
};