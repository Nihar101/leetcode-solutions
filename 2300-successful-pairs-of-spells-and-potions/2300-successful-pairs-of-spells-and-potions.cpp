class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<long long > totalup (100101);
        map<long long,long long> m;
        for(int i =0;i<potions.size();i++){
            m[potions[i]]++;
        }
        for(auto x: m){
            totalup[x.first]= x.second;
        }
        for(int i=totalup.size()-2;i>=0;i--){
            totalup[i]= totalup[i+1]+totalup[i];
        }
        vector<int> ans(spells.size());
        for(int i =0;i<spells.size();i++){
            long long mini = (success+spells[i]-1)/spells[i];
            if(mini>100000)continue;
            ans[i]= totalup[mini];
        }
        return ans;
    }
};