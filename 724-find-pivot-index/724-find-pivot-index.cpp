class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        int sum=0, current=0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        
        for(int i=0; i<n; i++){
            if(current == (sum-nums[i]-current))
                return i;
            current += nums[i];
        }
        return -1;
    }
};