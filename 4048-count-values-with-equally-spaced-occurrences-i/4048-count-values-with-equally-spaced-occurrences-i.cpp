class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> s(101);
        int count=0;
        for(int i=0;i<nums.size();i++){
            s[nums[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(s[i].size()==3){
                if(s[i][2]-s[i][1]==s[i][1]-s[i][0]){
                    count++;
                }
            }
        }
        return count;
    }
};