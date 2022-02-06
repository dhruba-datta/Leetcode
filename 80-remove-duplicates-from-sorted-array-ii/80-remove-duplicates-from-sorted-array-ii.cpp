//Solution 01:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, count = 1;
        if(n < 2) return n;
        
        while(i < n-1){
            if(nums[i] == nums[i+1]){
                count++;
                if(count <= 2){
                    nums[j] = nums[i];
                    j++;
                }
            }
            else{
                nums[j] = nums[i+1];
                count = 1;
                j++;
            }
            i++;
        }
        return j;
    }
};