class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        int mn = INT_MAX, mx = INT_MIN;
        
        for(auto x: nums){
            mx = max(mx, x);
            mn = min(mn, x);
        }
        
        for(auto x: nums){
            if(x>mn && x<mx) ans++;
        }
        /*
        sort(nums.begin(), nums.end());
        
        if(n<=2) return 0;
        if(nums[0] != nums[1] && nums[n-1] != nums[n-2]) return n-2;
        
        int i=0, j=n-1;
        
        while(i<n && nums[i]==nums[i+1]) i++;
        while(j>=0 && nums[j]==nums[j-1]) j--;
        
        if(j>i) return j-i-1;
        else if(i+1 == j) return 0;
        */
        return ans;
    }
};