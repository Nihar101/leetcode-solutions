class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost(s.size()+1);
        for(int i=0;i<s.size();i++){
            cost[i+1]= cost[i]+abs(s[i]-t[i]);
        }
        queue<int> q;
        q.push(0);
        int maxi =0;
        for(int i=1;i<cost.size();i++){
            while(q.size()&&(cost[i]-cost[q.front()]>maxCost))q.pop();
            if(q.size())maxi = max(maxi,i-q.front());
            q.push(i);
        }
        return maxi;
    }
};