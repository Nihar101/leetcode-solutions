class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0;
        int j = costs.size() - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int c = candidates;
        while (c--&&i<=j) {
            pq.push({costs[i++], 0});
            if (i <= j)pq.push({costs[j--], 1});
        }
        long long total = 0;
        for (int a = 0; a < k; a++) {
            total += pq.top().first;
            std::cout << pq.top().first << endl;
           
            int u = pq.top().second;
             pq.pop();
            if (i <= j) {
                if (u ==0)
                    pq.push({costs[i++], 0});
                else
                    pq.push({costs[j--], 1});
            }
            
        }
        return total;
    }
};