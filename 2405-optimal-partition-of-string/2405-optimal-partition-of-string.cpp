class Solution {
public:
    int partitionString(string s) {
        map<int,int> m;
        int count =0;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==0){
                m[s[i]]++;
            }
            else{
                count++;
                m.clear();
                m[s[i]]++;
            }
        }
        return count+1;
    }
};