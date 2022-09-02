class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int nums1=-1, nums2=-1, c1=0, c2=0, n=nums.size();
        vector<int>ans;
        
        for(auto x: nums){
            if(x == nums1) c1++;
            else if(x == nums2) c2++;
            else if(c1 == 0){
                nums1 = x;
                c1 = 1;
            }
            else if(c2 == 0){
                nums2 = x;
                c2 = 1;
            }
            else{
                c1--; c2--;
            }
        }
        
        c1=0; c2=0;
        
        for(auto x:nums){
            if(x == nums1) c1++;
            else if(x == nums2) c2++;
        }
        
        if(c1 > n/3) ans.push_back(nums1);
        if(c2 > n/3) ans.push_back(nums2);
        
        return ans;
    }
};