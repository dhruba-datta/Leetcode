class Solution {
public:
    int fib(int n) {
        int ans[n+2];
        ans[0]=0;
        ans[1]=1;
        
        for(int i=2; i<=n; i++)
            ans[i]=ans[i-1]+ans[i-2];
        
        return ans[n];
    }
};