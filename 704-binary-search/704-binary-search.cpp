class Solution {
public:
    int ans(int start, int end, int target, vector<int>& nums){
        if(start <= end){
            int mid = (end+start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) return ans(start, mid-1, target, nums);
            else  return ans(mid+1, end, target, nums);  
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int result = ans(0, nums.size()-1, target, nums);
        return result;
    }
};