class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<s.size();i++){
            m1[s[i]]++;
        }
        m2= m1;
        vector<int> ans;
        int count=0;
        for(int i=0;i<s.size();i++){
            count++;
            m2[s[i]]--;
            bool k = true;
            for(auto x: m1){
                if(m1[x.first]==m2[x.first]||m2[x.first]==0)continue;
                else{
                    k=false;
                    break;
                }
            }
            if(k){
                ans.push_back(count);
                count=0;
            }
        }
        return ans;
    }
};