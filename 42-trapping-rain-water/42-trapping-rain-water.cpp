class Solution {
public:
    int trap(vector<int>& h) {
        int lm=0, rm=0, l=0, r=h.size()-1, ans=0;
        
        while(l<r){
            if(h[l] <= h[r]){
                if(h[l] >= lm) lm = h[l];
                else ans += lm-h[l];
                l++;
            }
            else{
                if(h[r] >= rm) rm = h[r];
                else ans += rm-h[r];
                r--;
            }
        }
        return ans;
    }
};