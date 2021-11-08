class Solution {
public:
    void findSet(int idx, vector<vector<int>> &ans, vector<int>& nums){
        if(idx==nums.size()-1){
            ans.push_back({});
            ans.push_back({nums[idx]});
        }
        else{
            findSet(idx+1, ans, nums);
            int n=ans.size();
            for(int i=0; i<n; i++){
                vector<int> temp= ans[i];
                temp.push_back(nums[idx]);
                ans.push_back(temp);
            }   
        }     
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        
        findSet(0, ans, nums);
        return ans;
    }
};