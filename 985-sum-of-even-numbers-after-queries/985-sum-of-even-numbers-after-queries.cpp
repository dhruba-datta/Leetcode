class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;    //idx,elm
        int sum=0;
        for(int i=0;i<nums.size();i++){
            mp[i]=nums[i];
            if(nums[i]%2==0){
                sum+=nums[i];
            }
        }
        
        vector<int> ans;
        for(auto &x:queries){
            int val=x[0];
            int idx=x[1];
            int prev_val=mp[idx];
            mp[idx]=prev_val+val;
            if(abs(prev_val)%2==1 && abs(prev_val+val)%2==0){
                sum+=val+prev_val;
            }
            else if(prev_val%2==0 && abs(val+prev_val)%2==0){
                sum+=val;
            }
            else if(prev_val%2==0 && abs(val+prev_val)%2==1){
                sum-=prev_val;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};