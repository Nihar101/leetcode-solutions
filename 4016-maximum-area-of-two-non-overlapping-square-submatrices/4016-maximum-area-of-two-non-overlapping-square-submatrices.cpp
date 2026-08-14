class Solution {
public:
   bool are(pair<int, int> a, pair<int, int> b, int c) {
    pair<int, int> first0 = {a.first - c + 1, a.second - c + 1};
    pair<int, int> first1 = {a.first, a.second - c + 1};
    pair<int, int> first2 = {a.first - c + 1, a.second};
    pair<int, int> first3 = {a.first, a.second};

    pair<int, int> second0 = {b.first - c + 1, b.second - c + 1};
    pair<int, int> second1 = {b.first, b.second - c + 1};
    pair<int, int> second2 = {b.first - c + 1, b.second};
    pair<int, int> second3 = {b.first, b.second};

    if ((first0.second <= second2.second &&
         second0.second <= first2.second) &&
        (first0.first <= second1.first &&
         second0.first <= first1.first))
        return false;

    return true;
}
    int maxArea(vector<vector<int>>& mat) {
        vector<vector<pair<int, int>>> ans(501);
        vector<vector<int>> check(mat.size(), vector<int>(mat[0].size()));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 0){
                    check[i][j] = 0;
                     continue;
                }    
                else {
                    if (i == 0 || j == 0) {
                        check[i][j] = 1;
                       ans[1].push_back({i, j});
                     continue;
                    } else {
                        int a = min(check[i - 1][j], check[i][j - 1]);
                        a = min(check[i - 1][j - 1], a);
                        check[i][j] = a + 1;
                        ans[a + 1].push_back({i, j});
                    }
                }
            }
        }
        for (int i = ans.size() - 1; i >= 1; i--) {
            if (ans[i].size() <= 1)
                continue;
            else {
                for (int j = 0; j < ans[i].size(); j++) {
                    for (int k = j + 1; k < ans[i].size(); k++) {
                        if (are(ans[i][j], ans[i][k], i)) {
                            return i * i;
                        }
                    }
                }
            }
        }
        return 0;
    }
};