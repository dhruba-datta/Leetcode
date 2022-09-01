class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), r=0, w=0;
        
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[r]);
                w++; r++;
            }
        }
        
        for(int i=w; i<n; i++){
            if(nums[i] == 1){
                swap(nums[i], nums[w]);
                w++;
            }
        }
    }
};