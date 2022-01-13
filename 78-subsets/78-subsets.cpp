class Solution {
    void solve(vector<vector<int>> &ans, int i, vector<int>& ip, vector<int> op){
        if(ip.size()==i){
            ans.push_back(op);
            return;
        }
        solve(ans, i+1, ip, op);        
        op.push_back(ip[i]);
        solve(ans, i+1, ip, op);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& ip) {
        vector<vector<int>> ans;
        vector<int>op;
        solve(ans, 0, ip, op);
        return ans;
        
    }
};