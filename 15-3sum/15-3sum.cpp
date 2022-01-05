class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        
        if(n<3 || nums[0]>0)
            return {};
        
        vector<vector<int>>ans;  
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++)
            mp[nums[i]]=i;

        for(int i=0; i<n-2; i++){
            if(nums[i]>0) //we can't get 0 from here on
                break;
            
            for(int j=i+1; j<n-1; j++){
              
                if(mp.count(-(nums[i]+nums[j])) && mp.find(-(nums[i]+nums[j]))->second > j)
                    ans.push_back({nums[i],nums[j],-(nums[i]+nums[j])});
                
                j = mp.find(nums[j])->second; //Update j to last occurence of 2nd fixed number to avoid duplicate triplets.
            }
            i = mp.find(nums[i])->second;     //Update i to last occurence of 1st fixed number to avoid duplicate triplets.
        }
         
        return ans;
    }
};