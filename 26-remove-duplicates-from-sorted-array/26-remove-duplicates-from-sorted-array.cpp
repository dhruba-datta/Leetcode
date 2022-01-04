class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int  n=nums.size();
        
        if(n<=1)
            return n;
        
        int ans=1, x=nums[0], j=1;
        
        for(int i=1; i<n; i++){
            if(x != nums[i]){
                nums[j]= nums[i];
                j++;
                x= nums[i];
                ans++;
            }
        }
        return ans;
    }
};