class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, a=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0)
                a=nums[i];
            if(a==nums[i])
                count++;
            else
                count--;
        }
        return a;
    }
};