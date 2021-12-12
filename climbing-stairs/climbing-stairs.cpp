class Solution {
public:
    int climbStairs(int n) {
        int t[n+1];
        
        t[1]=1;
        if(n>=2) t[2]=2; //if we don't give the condition then it will give runtime error for i/p 1
        
        for(int i=3; i<=n; i++)
            t[i]= t[i-1]+t[i-2];
        
        return t[n];
    }
};