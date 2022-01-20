class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return true;
        
        int temp=0;
        
        for(int i=0; i<n-1; i++){
            temp = max(temp, i+nums[i]);
            if(temp == i) return false;
            if(temp >= n-1) return true;
        }
        return false;
    }
    
};