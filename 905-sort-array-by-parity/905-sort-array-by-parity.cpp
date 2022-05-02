class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int x=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 0 && i == 0) x++;
            
            else if(nums[i] % 2 == 0 && i != 0){
                swap(nums[i], nums[x]);
                x++;
            }
        }
        return nums;
    }
};