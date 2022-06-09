class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l = 0, h = x, ans;
        
        while(l <= h){
            int mid = (h+l) >> 1;
            
            if(mid == 0) return 1;
            if(mid == x/mid) return mid;
            else if(mid < x/mid){
                l = mid+1;
                ans = mid;
            } 
            else h = mid-1;
        }
        
        return ans;
    }
};
