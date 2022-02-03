class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size(), count=0;
        unordered_map<int, int> mp;
        
        for(auto i:nums1){
            for(auto j:nums2){
                mp[i+j]++;
            }
        }
        
        for(auto i:nums3){
            for(auto j:nums4){
                if(mp.find(0-(i+j)) != mp.end())
                    count += mp[0-(i+j)];
            }
        }
        return count;
    }
};