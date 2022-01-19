class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int n= hc.size(), m=vc.size();
        
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        int mxh = max(hc[0]-0 , h-hc[n-1]);
        int mxv = max(vc[0]-0 , w-vc[m-1]);

        for(int i=1; i<n; i++)
            mxh = max(mxh, hc[i]-hc[i-1]);   
     
        for(int i=1; i<m; i++)
            mxv = max(mxv, vc[i]-vc[i-1]);
        
        int mod = 1e9+7;
        
        return (((long long)mxv%mod)*((long long)mxh%mod))%mod;
    }
};