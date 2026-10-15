class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int count =0;
        int prev=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(prev==nums[i]||prev==-1){
                count++;
                
            }
            else{
                
                count=1;
            }
            if(count==m[nums[i]])ans++;
            prev=nums[i];
        }
        return ans;
    }
};