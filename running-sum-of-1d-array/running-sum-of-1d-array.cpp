class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans += nums[i];
            res.push_back(ans);
        }
        return res;
    }
};