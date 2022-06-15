class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int a2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ans1, ans2;
        
        ans1 = (a1<nums.size() && nums[a1] == target) ? a1 : -1;
        ans2 = (a2>0 && nums[a2-1] == target) ? a2-1 : -1;
        
        return {ans1, ans2};
    }
};