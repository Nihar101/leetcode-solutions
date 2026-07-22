class TimeMap {
public:
    map<string,vector<pair<int,string>>> m;
    TimeMap() {
        return;
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
        return;
    }
    
    string get(string key, int timestamp) {
       
        for(int i =m[key].size()-1;i>=0;i--){
            if(m[key][i].first<=timestamp)return m[key][i].second;
        }
         return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */