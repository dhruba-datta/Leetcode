class Solution {
public: 
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(), 0);

        help(nums, ans, temp, vis);
        return ans;
    }
    void help(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, vector<int> &vis){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i] = 1;
                help(nums, ans, temp, vis);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
};