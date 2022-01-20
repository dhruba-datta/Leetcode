class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mn=INT_MAX, mx=INT_MIN;
        int n=nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[i]>0 && mn>nums[i])
                mn = nums[i];
            if(nums[i]<1 || nums[i]>n) 
                nums[i]=1;
        }
        if(mn > 1)
            return 1;
        
        for(int i=0; i<n; i++){
            if(nums[abs(nums[i])-1]>0) 
                nums[abs(nums[i])-1] *= -1;
            
        }
        
        for(int i=0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        
        return n+1;
    }
};