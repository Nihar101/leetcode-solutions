class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int e= events[0][1];
        int value=events[0][2];
        int maxvalue = 0;
        int maxans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({e,value});
        for(int i =0;i<events.size();i++){
            while(pq.size()&&events[i][0]>pq.top().first){
                maxvalue=max(pq.top().second,maxvalue);
                pq.pop();
            }
            maxans= max(maxans,maxvalue+events[i][2]);
            pq.push({events[i][1],events[i][2]});
        }
        return maxans;
    }
};