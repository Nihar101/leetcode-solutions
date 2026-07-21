class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int count = 0;
        for(int i =0;i<nums.size();i++){
            if(m[k-nums[i]]!=0){
                count++;
                m[k-nums[i]]--;
            }
            else{
                m[nums[i]]++;
            }
        }
        return count;
        
    }
};