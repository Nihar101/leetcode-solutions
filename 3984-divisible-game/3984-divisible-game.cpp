class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        set<int> s;
        for(int i =0;i<nums.size();i++){
            for(int j =2;j<=sqrt(nums[i])+1;j++){
                if(nums[i]%j==0){
                    s.insert(j);
                    if(nums[i]/j!=1)s.insert(nums[i]/j);
                }
            }
            if(nums[i]!=1)s.insert(nums[i]);
        }
        int mod = 1e9+7;
        int minik = 1000000;
        long long maxidiff = INT_MIN;
        s.insert(2);
        for(auto k: s){
            vector<long long> prefix(nums.size()+1);
            long long mini = 0;
            long long currmaxidiff= INT_MIN;//yellow flag
            for(int i =0;i<nums.size();i++){
                if(nums[i]%k==0){
                    prefix[i+1]= prefix[i]+nums[i];
                }
                else{
                    prefix[i+1]= prefix[i]-nums[i];
                }
                currmaxidiff = max(currmaxidiff,prefix[i+1]-mini);
                //std::cout<<currmaxidiff<<endl;
                mini = min(mini,prefix[i+1]);
            }
            if(currmaxidiff>maxidiff){
                minik = k;
                maxidiff= currmaxidiff;
            }
        }
        
        int fina = ((maxidiff%mod)*minik)%mod;
        if(fina<0)return fina+mod;
        return fina;
    }
};