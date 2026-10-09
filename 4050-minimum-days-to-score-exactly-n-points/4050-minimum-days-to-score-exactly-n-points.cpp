class Solution {
public:
    int call(vector<int> &dp,int left){
        if(left==0)return left;
        if(dp[left]!=-1)return dp[left];
        int k=1;
        int ans =INT_MAX;
        while(true){
            int y=1;
            int points = ((k+1)*k)/2;
            if(points>left)break;
            if(points==left)y=0;
            int u=call(dp,left-points)+k;
            ans = min(ans,u+y);
            k++;
        }
        return dp[left]=ans;
    }
    int minDays(int n) {
        vector<int> dp(n+1,-1);
        return call(dp,n);
    }
};