class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        vector<long long> prefix(nums.size());
        long long total= 0;
        for(auto x:nums)total+=x;
        int a=0;
        int b=nums.size()/2;
        long long half=0;
        for(int i=0;i<nums.size()/2;i++){
            half+= nums[i];
        }
        int n = nums.size();
        n--;
        prefix[b-1]=half;
        int u=nums.size();
        while(n--){
            prefix[b]=nums[b]+half-nums[a];
            half = prefix[b];
            a= (a+1)%u;
            b= (b+1)%u;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(total<2*prefix[i])count++;
        }
        return count;
    }
};