class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        int ans, sum, mn= INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-2; i++){
            int left = i+1;
            int right = n-1;
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(sum == target)
                    return sum;
                else if(sum < target)
                    left++;
                else
                    right--;
                if( abs(sum - target) < mn){
                    ans = sum;
                    mn = abs(sum - target);
                }
            }
        }
        
        return ans;
        
    }
};