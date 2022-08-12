class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> t(n+1, {0,0});
        
        for(int i=0; i<trust.size(); i++){
            t[trust[i][0]].first += 1;
            t[trust[i][1]].second += 1;
        }
        
        for(int i=1; i<=n; i++){
            if(t[i].first == 0  &&  t[i].second == n-1)
                return i;
        }
        return -1;
    }
};