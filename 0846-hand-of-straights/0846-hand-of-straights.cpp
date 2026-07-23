class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gr) {
        map<int,int> m ;
        for(int i =0;i<hand.size();i++){
            m[hand[i]]++;
            
        }
        int going = 0;
        int prev=-2;
        map<int,int> down;
        for(auto x:m){
            int a = x.first;
            if(going>m[a])return false;
            if(going&&prev!=-2&&prev!=a-1)return false;
            int left = m[a]-going;
            going+=left;
            prev =a;
            down[a+gr-1]=left;
            if(down[a])going-=down[a];
        }
        if(going)return false;
        return true;
    }
};