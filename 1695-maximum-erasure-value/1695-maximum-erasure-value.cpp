class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> m;
        int j=0;
        int a =0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==0){
                m[nums[i]]++;
                a+= nums[i];
            }    
            else{
                while(m[nums[i]]!=0){
                    m[nums[j]]--;
                    a-= nums[j];
                    j++;
                }
                m[nums[i]]++;
                a+=nums[i];
            }
            ans =max(a,ans);
        }
        return ans;
    }
};