class Solution {
public:
    int countRotations(string s, int k) {
         int count=0;
        for(int i=0;i<s.size();i++){
           
            if(s[i]==s[(i+1)%s.size()])count++;
        }
        if(k==count)return s.size()-count;
        if(k==count-1)return count;
        return 0;
    }
};