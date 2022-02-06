class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, length = 1, count = 1;
        if(n < 2) return n;
        
        while(i < n-1){
            if(nums[i] == nums[i+1]){
                count++;
                if(count <= 2){
                    nums[length] = nums[i];
                    length++;
                }
            }
            else{
                nums[length] = nums[i+1];
                count = 1;
                length++;
            }
            i++;
        }
        return length;
    }
};