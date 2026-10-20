class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int prev=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
           if(prev!=nums[i]||(prev==nums[i]&&count<k)){
              if(prev!=nums[i])count=0;
              count++;
              prev=nums[i];
              ans.push_back(nums[i]);
           }
           else{
            continue;
           }
        }  
      return ans;
    }
};