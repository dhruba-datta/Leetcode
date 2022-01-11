class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n= nums.size(), x=nums[0];
        
        for(int i=0; i<n-1; i++){
            if(i==0 && nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==nums[i+1] && nums[i]!=x){
                ans.push_back(nums[i]);
                x = nums[i];
            }
        }
        return ans;
    }
};