class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)count++;
        }
        std::cout<<count;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0&&i<=int(nums.size()-1-count))ans++;
        }
        return ans;
    }
};