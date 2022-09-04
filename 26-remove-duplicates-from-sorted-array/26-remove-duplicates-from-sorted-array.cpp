class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), x=-200, j=0, ans=0;
        
        for(int i=0; i<n; i++){
            if(x != nums[i]){
                x = nums[i];
                nums[j] = x;
                j++;
                ans++;
            }
        }
        return ans;
    }
};