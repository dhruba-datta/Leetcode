class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());
        int count = 1, ans = -1;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] == nums[i]+1){
                count++;
                cout<<count<<" ";
            }
            else if(nums[i+1] == nums[i]) continue;
            else{
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};