class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        map<int,int> m;
        int prev=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(i==0||nums[i]>prev)m[i]=nums[i];
            prev = max(prev,nums[i]);
        }
        prev=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1||nums[i]>prev)m[i]=nums[i];
            prev=max(prev,nums[i]);
        }
        vector<int> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};