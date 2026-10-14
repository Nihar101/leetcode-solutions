class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int ans=0;
        for(int i=-1;i<(int)nums.size();i++){
            vector<int> k;
            int m=0;
            for(int j=0;j<nums.size();j++){
                if(i!=j)k.push_back(nums[j]);
            }
            vector<int> l(k.size()+1,0);
            for(int a=1;a<l.size();a++){
                l[a]=gcd(k[a-1],l[a-1]);
            }
            vector<int> r(k.size()+1,0);
            for(int a=r.size()-2;a>=0;a--){
                r[a]= gcd(r[a+1],k[a]);
            }
            for(int a=1;a<k.size();a++){
                if(l[a]==r[a])m++;
            }
            ans = max(ans,m);
        }
        return ans;
    }
};