class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int lowest_speed =speed[speed.size()-1];
        int groups=position.size();
        unordered_map<int,int> m;
        for(int i=0;i<position.size()-1;i++){
            if(position[i+1]-position[i]<=distance){
                groups--;
                m[i]=-1;
            }
        }
        for(int i=position.size()-2;i>=0;i--){
            if(speed[i]>lowest_speed&&m[i]!=-1)groups--;
            if(m[i]!=-1)lowest_speed = min(lowest_speed,speed[i]);
        }
        return groups;
    }
};