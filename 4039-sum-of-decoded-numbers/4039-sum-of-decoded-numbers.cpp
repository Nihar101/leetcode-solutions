class Solution {
public:
long long MOD = 1e9+7;
    long long powr(long long x,long long y){
        long long result =1;
        x=(x%MOD);
        while(y){
            x%=MOD;
            if(y&1)result*=x;
            x*=x;
            y>>=1;
            result%=MOD;
        }
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        int ans =0;
        
        for(int i=0;i<nums.size();i++){
            long long  k =nums[i];
            long long w = k%10;
            long long di = k/10;
            stack<int> st;
            while(di){
                int y= di%10;
                di/=10;
                st.push(y);
            }
            long long x = 0;
            while(w--){
                x=x*10+st.top();
                st.pop();
            }
            long long y =0;
            while(st.size()){
                y = y*10+st.top();
                st.pop();
            }
            x%=MOD;
            y%=MOD;
            long long s = powr(x,y);
            s = s%MOD;
            ans =(s+ans)%MOD;
        }
        return ans;
    }
};