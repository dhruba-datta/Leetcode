class Solution {
public:
    void fun(int idx, int target, vector<int> &arr, vector<vector<int>>&ans, vector<int>&var){
        if(target == 0){
            ans.push_back(var);
            return;
        }
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            var.push_back(arr[i]);
            fun(i+1, target-arr[i], arr, ans, var);
            var.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> var;
        fun(0, target, arr, ans, var);
        return ans;
    }
};