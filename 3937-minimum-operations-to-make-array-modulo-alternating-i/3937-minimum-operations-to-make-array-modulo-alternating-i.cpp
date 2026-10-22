class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> ans1;
        vector<int> ans2;
        int ans =INT_MAX;
        vector<int> dup = nums;
        for(int i=0;i<nums.size();i++){
            dup[i]= nums[i]%k;
        }
        for(int a=0;a<k;a++){
            int l=0;
            for(int i=0;i<nums.size();i+=2){
                l+= min(abs(a-dup[i]),k-abs(a-dup[i]));
            }
            ans1.push_back(l);
            l=0;
            for(int i=1;i<nums.size();i+=2){
                l+= min(abs(a-dup[i]),k-abs(a-dup[i]));
            }
            ans2.push_back(l);
            
        }
        for(int i=0;i<ans1.size();i++){
            for(int j=0;j<ans2.size();j++){
                if(i!=j){
                    ans = min(ans,ans1[i]+ans2[j]);
                }
            }
        }
        return ans;
    }
};