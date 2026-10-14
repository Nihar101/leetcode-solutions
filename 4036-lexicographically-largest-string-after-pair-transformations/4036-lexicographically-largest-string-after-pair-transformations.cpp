class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            int k = nums[i];
            string s;
            s="";
            for(int j=25;j>=0;j--){
                if(j==25){
                    int y=k/(1<<25);
                    while(y--){
                        s+="z";
                    }
                }
                else{
                    if(k&(1<<j)){
                        s+= 'a'+j;
                    }
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};