class Solution {
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        int maxia = 0;
        int maxib = 0;
        sort(hs.begin(),hs.end());
        sort(vs.begin(),vs.end());
        for(int i=0;i<hs.size();i++){
           if(i>0)maxia = max(maxia,hs[i]-hs[i-1]);
        }
        maxia = max(hs[0]-0,maxia);
        maxia = max(h-hs[hs.size()-1],maxia);
        for(int i=0;i<vs.size();i++){
             if(i>0)maxib = max(maxib,vs[i]-vs[i-1]);
            
        }
        maxib = max(vs[0]-0,maxib);
        maxib = max(w-vs[vs.size()-1],maxib);
        int mod = 1e9 +7;
        std::cout<<maxia<<endl<<maxib;
        long long t= maxia%mod;
        long long s = maxib%mod;
        long long ans = (t*s)%mod;
        int as = ans;
        return as;
        
    }
};