class Solution {
public:
    bool validDigit(int n, int x) {
        bool k=false;
        while(n>9){
            if(n%10==x)k= true;
            n/=10;
        }
        if(n%10==x)k=false;
        return k;
    }
};