class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = n;
        
        if(m<0) m *= -1;
        
        while(m){
            if(m % 2){
                ans *= x;
                m--;
            }
            else{
                x *= x;
                m /= 2;
            }
        }
        
        return (n<0) ? 1.0/ans : ans;
    }
};