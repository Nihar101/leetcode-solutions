class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        map<long long ,int> m;
        

        map<long long, int> s;
        vector<pair<long long,int>> ds;
        for(int i =0;i<planks.size();i++){
            m[planks[i]]++;
        }
        for(auto x: m){
            ds.push_back({x.first,x.second});
        }
        for(int i=0;i<ds.size();i++){
            for(int j=i;j<ds.size();j++){
                if(i==j){
                    m[ds[i].first*2]+= ds[i].second/2;
                }
                else{
                    int h = min(ds[i].second,ds[j].second);
                    m[ds[i].first+ds[j].first]+= h;
                }
            }
        }
        int ans = 0;
        int u =0;
        for(auto x: m){
            if(m[ans]<x.second){
                u = x.second;
                ans = x.first;
            }
        }
        return u;
    }
};