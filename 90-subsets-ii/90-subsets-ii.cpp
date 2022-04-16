class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        help(0, nums);
        return ans;
    }
    
    void help(int index, vector<int>& nums){
        ans.push_back(temp);
        
        for(int i=index; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            help(i+1, nums);
            temp.pop_back();
        }
    }
};