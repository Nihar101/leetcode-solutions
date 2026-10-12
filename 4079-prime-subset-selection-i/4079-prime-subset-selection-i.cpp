class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        vector<int> isprime(n+1,1);
        isprime[1]=isprime[0]=false;

        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
            
        }
        for(int i=0;i<=n;i++){
            if(isprime[i])ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        vector<int> ff;
        int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+= ans[i];
            if(sum<=s)ff.push_back(ans[i]);
            else break;
        }
        return ff;
    }
};