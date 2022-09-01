class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1, idx2, n=nums.size();
        
        for(idx1=n-2; idx1>=0; idx1--){
            if(nums[idx1] < nums[idx1+1])
                break;
        }
        
        if(idx1 < 0) reverse(nums.begin(), nums.end());
        
        else{
            for(idx2=n-1; idx2>=0; idx2--){
                if(nums[idx2] > nums[idx1])
                    break;
            }
            swap(nums[idx1], nums[idx2]);
            reverse(nums.begin()+idx1+1, nums.end());
        }
        
    }
};