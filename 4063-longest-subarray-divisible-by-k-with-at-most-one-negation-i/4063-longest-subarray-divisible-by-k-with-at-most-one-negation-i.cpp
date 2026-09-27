class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans =0;
        for(int i =0;i<nums.size();i++){
            unordered_map<int,int> m;
            long long s =0;
            for(int j=i;j<nums.size();j++){
                int  val = ((2LL*nums[j])%k+k)%k; 
                m[val]++;
                s+= nums[j];
                if(s%k==0)ans = max(ans,j+1-i);
                else {
                    int rem = ((s%k)+k)%k;
                    if(m[rem]!=0)ans =max(ans,j+1-i);
                }
            }
            
        }
        return ans;
    }
};