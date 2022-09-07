class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        help(nums, ans, temp, 0);
        return ans;
    }
    
    void help(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int idx){
        ans.push_back(temp);
        
        for(int i=idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            help(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
};
