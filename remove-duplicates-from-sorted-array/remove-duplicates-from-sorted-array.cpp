class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        set <int> a;
        for(int i=0; i<n; i++){
            a.insert(nums[i]);
        }
        int ans = a.size();
        int i=0;
        for(auto x:a){
            nums[i]=x;
            i++;
        }
        return ans;
    }
};