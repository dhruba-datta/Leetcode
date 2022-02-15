class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        for(auto x:nums)
            ans = ans ^ x;
        
        return ans;
    }
};