class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans =0;
        for (int d = 0; d < 26; d++) {
            char x = 'A' + d;
            int i = 0;
            int j = 0;
            int used=k;
            while (i <= j && j < s.size()) {
                if(s[j]==x){
                    j++;
                }
                else if(used){
                    used--;
                    j++;
                }
                else if(i==j){
                    i++;
                    j++;
                }
                else {
                    while(!used&&i<j){
                        if(s[i]!=x&&used<k)used++;
                        i++;
                    }
                }
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};