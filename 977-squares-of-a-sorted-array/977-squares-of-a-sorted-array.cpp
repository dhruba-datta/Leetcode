class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size()-1;
        int l=0, r=n;
        vector<int> ans(nums.begin(), nums.end());
        
        while(n>=0){
            if(nums[l]*nums[l] > nums[r]*nums[r]){
                ans[n] = nums[l]*nums[l];
                l++; n--;
            }
            else{
                ans[n] = nums[r]*nums[r];
                r--; n--;
            }
        }
        
        return ans;
    }
};