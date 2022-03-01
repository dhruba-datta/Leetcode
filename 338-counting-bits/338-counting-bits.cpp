class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
      
        dp[0]=0;
        int k=1;
       
        for(int i=1; i<=n; i++){
            if(k*2==i)
                k = k*2;
            
            dp[i]= 1+dp[i-k];  
        }
       
        return dp;
    }
};