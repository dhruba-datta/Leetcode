class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return help(0,0,m,n,dp);
    }
    
    int help(int start, int end, int m, int n, vector<vector<int>> &dp){
        if(start > m || end > n) return 0;
        if(start == m-1 && end == n-1) return 1;
        
        if(dp[start][end] != -1) return dp[start][end];
        return dp[start][end] = help(start+1, end, m, n, dp) + help(start, end+1, m, n, dp);
    }
};