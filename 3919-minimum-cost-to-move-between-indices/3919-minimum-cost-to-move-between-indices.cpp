class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> prefix(nums.size(),0);
        vector<int> postfix(nums.size(),0);
        for(int i=0;i<prefix.size()-1;i++){
            int k=0;
            if(i==0||(abs(nums[i]-nums[i+1])<abs(nums[i]-nums[i-1])))k=1;
            else k= abs(nums[i+1]-nums[i]);
            prefix[i+1]= prefix[i]+ k;
        }
        for(int i=nums.size()-1;i>0;i--){
            int k=0;
            if(i==nums.size()-1||(abs(nums[i+1]-nums[i])>=abs(nums[i]-nums[i-1])))k=1;
            else k= abs(nums[i-1]-nums[i]);
            postfix[i-1]=postfix[i]+k;
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r= queries[i][1];
            int h =0;
            if(l<r){
                h = prefix[r]-prefix[l];
            }
            else h = postfix[r]-postfix[l];
            ans[i]=h;
        }
        return ans;
    }
};