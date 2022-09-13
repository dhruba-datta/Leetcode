class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        help(ans, nums, 0);
        return ans;
    }
    
    void help(vector<vector<int>> &ans, vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            help(ans, nums, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};