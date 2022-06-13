class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(lower_bound(nums.begin(), nums.end(), target)-nums.begin() != nums.size() && nums[lower_bound(nums.begin(), nums.end(), target)-nums.begin()] == target)
            return lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        return -1;
    }
};