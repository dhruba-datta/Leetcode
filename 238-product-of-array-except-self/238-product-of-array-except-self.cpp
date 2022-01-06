class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(), p=1;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            p *= nums[i];
            ans[i]=p;
        }
        
        int product=1;
        for(int i=n-1; i>0; i--){
            ans[i]= ans[i-1]*product;
            product *= nums[i];
        }
        ans[0]=product;
        
        return ans;
    }
};