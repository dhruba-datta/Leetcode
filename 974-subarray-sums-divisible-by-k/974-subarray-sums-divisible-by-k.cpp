class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0, count=0;
        int n=nums.size();
        vector<int> mp(k, 0);
        
        for(auto x:nums){
            sum += (x%k+k)%k;
            mp[sum%k]++;
        }
        count = mp[0];
        
        for(int a:mp){
            count +=  (a*(a-1))/2;
        }
        
        return count;
    }
};