class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n= nums.size();
        int count=0, l=0, r=n-1;
        sort(nums.begin(), nums.end());
        unordered_map<int, int>mp;
        
        if(k<0) return 0;
        
        for(auto x: nums)
            mp[x]++;
        if(k==0){
            for(auto x:mp){
                if(x.second>1)
                    count++;
            }
        }
        else{
            for(auto x:mp){
                x.second--;
                if(mp.count(x.first-k))
                    count++;
                x.second++;
            }    
        }
        
        return count;
    }
};  