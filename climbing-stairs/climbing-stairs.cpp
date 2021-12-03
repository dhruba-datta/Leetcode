class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        
        int x=1, y=2;
        
        for(int i=3; i<n; i++){ // if i<=n
            int temp = y;
            y += x;
            x = temp;
        }
        return x+y; // return y
    }
};