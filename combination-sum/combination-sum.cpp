class Solution {
public: 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> var;
        int n=candidates.size();
        fun(0, target, candidates, ans, var);
        return ans;
    }
    void fun(int idx, int target, vector<int> &candidates, vector<vector<int>>&ans, vector<int>&var){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(var);
            }
            return;
        }
        if(candidates[idx]<=target){
            var.push_back(candidates[idx]);
            fun(idx, target-candidates[idx], candidates, ans, var);
            var.pop_back();
        }
        fun(idx+1, target, candidates, ans, var);
    }
};