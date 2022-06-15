class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a1 = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int a2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ans1, ans2;
        
        if(a1<nums.size() && nums[a1] == target) ans1 = a1;
        else ans1 = -1;
        
        if(a2>0 && nums[a2-1] == target) ans2 = a2-1;
        else ans2 = -1;
        
        return {ans1, ans2};
    }
};