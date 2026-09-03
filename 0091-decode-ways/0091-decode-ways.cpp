class Solution {
public:
    set<string> ans;
    string l;
    int decode(int i, vector<vector<int>>& dp) {
        if (i == l.size()) {
            return 1;
        }
        if(l[i]=='0')return 0;
        if (i < l.size() - 1 ) {
            string f = l.substr(i,2);
            int k = stoi(f);
            if (k<=26&&dp[i][1] == -1) {
                dp[i][1] = decode(i + 2, dp);
            }
            std::cout<<dp[i][1]<<endl;
            
        }
        if (dp[i][0] == -1) {
            if(l[i]=='0')return 0;
            dp[i][0] = decode(i + 1, dp);
            std::cout<<dp[i][0]<<endl;
        }
        int k =0 ;
        if(dp[i][0]>0)k+=dp[i][0];
        if(dp[i][1]>0)k+=dp[i][1];
        return k;
    }
    int numDecodings(string s) {
        l = s;
        vector<vector<int>> dp(s.size() + 1, vector<int>(2, -1));
        return decode(0,dp);
    }
};