class Solution {
public:
    int n;
    long long score = 0;
    long long getSum(vector<int>& nums) {
        n = nums.size();
        vector<long long> prefix((2*nums.size()) + 2);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(0);
            ans.push_back(nums[i]);

        }
        ans.push_back(0);
        for(int i =1;i<prefix.size();i++){
            prefix[i]= prefix[i-1]+ans[i-1];

        }
        int rightmost=-1;
        int corm=-1;
        vector<int> pfc(ans.size());
        int s = ans.size();
        for(int i =0;i<ans.size();i++){
            int mini=0;
            if(rightmost>=i){
                int y = corm - (i-corm);
                int ray = pfc[y];
                 mini = min (ray+i,rightmost)-i;
                if(ray+i == rightmost){
                    int next= ray+1;
                    while(i-next>=0&&i+next<s&&(ans[i-next]==ans[i+next]))next++;
                    next--;
                    mini = next;
                }
                pfc[i]=mini;
            }
            else{
                int next= 1;
                    while(i-next>=0&&i+next<s&&(ans[i-next]==ans[i+next]))next++;
                    next--;
                    mini = next;
                    pfc[i]=mini;
            }
            if(rightmost<pfc[i]+i){
                rightmost = pfc[i]+i;
                corm = i;
            }
            score = max(score,prefix[i+pfc[i]+1]-prefix[i-pfc[i]]);
        }
        return score;
    }
};