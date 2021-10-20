class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n= nums.size();
        int product=nums[n-1]; //to keep track of right-left product
        
        //Now we create the ans array with left-right product
        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back(nums[i]);
            }
            else{
                int a= ans[ans.size()-1];
                ans.push_back(nums[i]*a);
            }
        }
        
        //Now we will modify the ans array and keep track of right-left product
        ans[n-1]= ans[n-2]; //Fix the last element of the ans array
        
        for(int i=n-2; i>0; i--){
            ans[i]= ans[i-1]*product;
            product *= nums[i];
        }
        ans[0]=product; //Fix the first element of the ans array
        
        return ans;
    }
};