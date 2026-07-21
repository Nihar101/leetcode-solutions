class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<vector<int>> prefix(s.size()+1, vector<int>(26,0));
        map<char,int> d;
        for(int i=0;i<p.size();i++){
            d[p[i]]++;
        }
        vector<int> ans;
        int l = p.size();
        for(int i =1;i<=s.size();i++){
            prefix[i]= prefix[i-1];
            int k = s[i-1]-'a';
            prefix[i][k]++;
            if(i>=l){
                map<char,int> a;
                for(int j=0;j<26;j++){
                    int x = prefix[i][j]-prefix[i-l][j];
                    char y = 'a' +j;
                    if(x)a[y]=x;
                }
                if(a==d)ans.push_back(i-l);
            }
        }
        return ans;
    }
};