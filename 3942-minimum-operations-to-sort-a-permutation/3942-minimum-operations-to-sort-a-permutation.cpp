class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool r=false;
        bool l = false;
        int n=nums.size();
        int count=0;
        int mini =INT_MAX;
        int midx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[(i+1)%n])count++;
            if(mini>nums[i]){
                mini  = nums[i];
                midx=i;
            }
        }
        if(count==n-1)r=true;
        count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n])count++;
        }
        if(count==n-1)l=true;
        int ans =-1;
        if(l||r){
            if(r)ans = min(3+n-1-midx,midx);
            else if(l)ans = 1+ min(n-1-midx,1+midx);
        }
        return ans;
    }
};