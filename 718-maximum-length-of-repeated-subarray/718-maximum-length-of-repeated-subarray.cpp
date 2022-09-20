class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n+1][m+1], ans = 0;
        memset(dp,0,sizeof(dp));
        for (auto i = 0; i < n; i++){
            for (auto j = 0; j < m; j++){
                if (nums1[i] == nums2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                    ans = max(ans,dp[i+1][j+1]);
                }                
            }
        }
        return ans;
    }
};