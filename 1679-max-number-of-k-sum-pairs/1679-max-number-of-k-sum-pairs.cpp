class Solution {
public:
    int maxOperations(vector<int>& nums, int sum) {
        unordered_map<int,int> freq;
        for(int e: nums) freq[e]++;
        int ans = 0;
        for(auto& [k,v]: freq){
            if(2*k == sum) ans += v / 2, v -= v/2*2; 
            else if(v > 0 && freq.count(sum-k) && freq[sum-k] > 0) {                
                int pair_cnt = min(v, freq[sum-k]);
                ans += pair_cnt;
                v -= pair_cnt;
                freq[sum-k] -= pair_cnt;                
            }            
        }
        return ans;
    }
};