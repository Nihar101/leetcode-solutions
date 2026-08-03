class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long> ch(tasks.size() + 1, 0);
        for (int i = 1; i < ch.size(); i++) {
            ch[i] = ch[i - 1] + tasks[i - 1];
        }
        vector<int> ans(shifts.size());
        int prev = 0;
        long long timegot = 0;
        for (int i = 0; i < shifts.size(); i++) {
            long long  timehaving = shifts[i] + timegot;
            int lo = prev;
            int hi = tasks.size();
            bool k = true;
            // if(ch[])
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (ch[mid] <= timehaving + ch[prev]) {

                    lo = mid + 1;
                    timehaving -= ch[mid] - ch[prev];
                    prev = mid;
                    k = false;
                    // std::cout<<"finished task till "<<mid<<"in
                    // shift"<<i<<endl;
                } else {
                    hi = mid - 1;
                }
            }
            ans[i] = (tasks.size() - prev);
            timegot = timehaving;
            if (prev == tasks.size()) {
                prev = 0;
                timegot = 0;
            }
        }
        return ans;
    }
};