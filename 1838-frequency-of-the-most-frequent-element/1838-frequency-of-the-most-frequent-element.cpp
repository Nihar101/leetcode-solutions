class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i =nums.size()-1;
        int j = i;
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int curr = nums[i];
        
        while(i>=0){
            if(nums[i]==curr)i--;
            else if(curr-nums[i]<=k){
                k-=curr-nums[i];
                i--;
            }
            else{
                maxi = max(j-i,maxi);
                while(nums[j]==curr)j--;
                int gap = curr-nums[j];
                curr = nums[j];
                k+= gap*(j-i);
            }
            maxi = max(j-i,maxi);
        }
        return maxi;
    }
};