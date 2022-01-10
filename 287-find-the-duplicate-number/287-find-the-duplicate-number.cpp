class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n+1, 0);
        
        for(auto x:nums){
            temp[x]++;
            if(temp[x] >1)
                return x;
        }
        return -1;
    }
};