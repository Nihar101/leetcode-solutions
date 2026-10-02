class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long count =0;
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<intervals.size();i++){
            if(pq.size()){
                while(pq.size()&&pq.top()<intervals[i][0])pq.pop();
                count+=pq.size();
            }
            pq.push(intervals[i][1]);
        }
        return count;
    }
};