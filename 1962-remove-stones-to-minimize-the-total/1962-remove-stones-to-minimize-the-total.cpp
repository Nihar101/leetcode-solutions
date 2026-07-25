class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        long long totalleft =0;
        for(int i =0;i<piles.size();i++){
            pq.push(piles[i]);
            totalleft+= piles[i];
        }

        while(k--&&totalleft&&pq.size()){
            int top = pq.top();
            pq.pop();
            int left = top- (top/2);
            pq.push(left);
            totalleft -= (top/2);
        }
        return int(totalleft);

    }
};