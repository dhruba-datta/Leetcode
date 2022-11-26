bool cmp(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    return a.first.second < b.first.second;
}

class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& en, vector<int>& prof) {
        int n = st.size();
        vector<pair<pair<int, int>, int>> jobs;
        map<int, int> dp = {{0, 0}};
        for (int i = 0; i < n; i++) jobs.push_back({{st[i], en[i]}, prof[i]});
        sort(jobs.begin(), jobs.end(), cmp);
        for (pair<pair<int, int>, int>& p : jobs) {
            auto it = dp.upper_bound(p.first.first);
            it--;
            if (dp.count(p.first.second) == 0) dp[p.first.second] = dp.rbegin()->second;
            dp[p.first.second] = max(p.second + it->second, dp[p.first.second]);
        }
        return dp.rbegin()->second;
    }
};