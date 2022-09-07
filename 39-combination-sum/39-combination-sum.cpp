class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        help(0, target, candidates);
        return ans;
    }
    
    void help(int idx, int t, vector<int>& c){
        if(idx == c.size()){
            if(t == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(t >= c[idx]){
            temp.push_back(c[idx]);
            help(idx, t-c[idx], c);
            temp.pop_back();
        }
        help(idx+1, t, c);
    }
};