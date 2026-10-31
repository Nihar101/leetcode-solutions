class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long inc =0;
        long long dec=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1])inc+= nums[i];
            if(i>0&&nums[i]>nums[i+1]&&nums[i]>nums[i-1])inc+=nums[i];
            if(nums[i]>nums[i+1]) dec+=nums[i];
        }
        dec+=nums[nums.size()-1];
        
        if(inc==dec)return -1;
        else if(inc>dec)return 0;
        return 1;
    }
};