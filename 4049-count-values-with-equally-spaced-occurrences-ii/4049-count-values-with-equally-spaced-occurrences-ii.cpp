class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> s(nums.size() + 1);
        map<int,int> m;
        int count=0;
        int idx=1;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0)m[nums[i]]=idx++;
            int k = m[nums[i]];
            s[k].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(s[i].size()>=3){
                bool u=true;
                for(int j=1;j<s[i].size()-1;j++){
                    if(s[i][j]-s[i][j-1]!=s[i][j+1]-s[i][j]){
                        u=false;
                        break;
                    }

                }
                if(u)count++;
            }
        }
        return count;
    }
};