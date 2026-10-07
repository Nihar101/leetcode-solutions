class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        stack <int> s;
        long long ans=0;
        long long  count=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            while(s.size()&&s.top()>nums[i]){
                
                m[s.top()]--;
                s.pop();
            }    
            ans+= (s.size()-m[nums[i]]);
            m[nums[i]]++;
            s.push(nums[i]);
        }
        return ans;
    }
};