class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int count=0;
        for(int i =n-1;i>=0;i--){
            if(s1[i]!=s2[i]){
                if(s1[i]=='0'&&s2[i]=='1'){
                    count++;
                    s1[i]='1';
                }
                else{
                    if(i!=0&&s1[i-1]=='1'&&s2[i-1]=='0'){
                        count++;
                        s1[i]='0';
                        s1[i-1]='0';
                    }
                    else if(i<n-1){
                        s1[i]='0';
                        count+=2;
                    }
                    else if(i!=0){
                        if(s1[i-1]==s2[i-1])count+=2;
                        if(s1[i-1]!=s2[i-1])count+=3;
                        s1[i-1]=s2[i-1];
                    }
                    else return -1;
                }
            }
        }
        return count;
    }
};