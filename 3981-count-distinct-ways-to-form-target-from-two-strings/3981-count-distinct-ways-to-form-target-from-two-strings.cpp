class Solution {
public:
    int mod = 1e9+7;
    int dp[101][101][101][4] ;
    int count(int i ,int j,int k,int mask,string &word1,string &word2,string &target){
        if(k==target.size()){
            if(3==mask)return 1;
            return 0;
        }
        int ans =0;
        if(dp[i][j][k][mask]!=-1)return dp[i][j][k][mask];
        for(int a=i;a<word1.size();a++){
            if(word1[a]==target[k])ans += count(a+1,j,k+1,mask|1,word1,word2,target);
            ans = ans%mod;
        }
        for(int b=j;b<word2.size();b++){
            if(word2[b]==target[k])ans+=count(i,b+1,k+1,mask|2,word1,word2,target);
            ans = ans%mod;
        }
        return dp[i][j][k][mask]=ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return count(0,0,0,0,word1,word2,target);
    }
};