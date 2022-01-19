class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(size(nums), 10001);
        return help(nums, dp, 0);
    }
    int help(vector<int>& nums,  vector<int>& dp, int start){
        if(start >= size(nums)-1) return 0;
        if(dp[start] != 10001) return dp[start];
        
        for(int i=1; i<=nums[start]; i++){
            dp[start] = min(dp[start], 1+help(nums, dp, start+i));
        }
        return dp[start];
    } 
};