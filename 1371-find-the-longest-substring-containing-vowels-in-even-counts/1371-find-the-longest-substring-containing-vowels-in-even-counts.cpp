class Solution {
public:
    int findTheLongestSubstring(string s) {
        int y = 0;
        map<int,int> m;
        m[0]=0;
        int maxi=0;
        vector<int> prefix(s.size()+1);
        prefix[0]=0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='a'){
                y= y^1;
            }
            else if(s[i]=='e'){
                y= y^(1<<1);
            }
            else if(s[i]=='i'){
                y= y^(1<<2);
            }
            else if(s[i]=='o'){
                y= y^(1<<3);
            }
            else if(s[i]=='u'){
                y= y^(1<<4);
            }
            if(y!=0&&m[y]==0)m[y]=i+1;
            else {
                maxi = max(i-m[y]+1,maxi);
            }
            prefix[i+1]=y;
        }
        return maxi;
    }
};