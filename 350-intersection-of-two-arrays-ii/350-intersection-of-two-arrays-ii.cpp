class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j] && nums1[i]!=-1 && nums2[j]!=-1)
                {
                    ans.push_back(nums1[i]);
                    nums1[i]=-1;
                    nums2[j]=-1;
                }
            }
        }
        return ans;
    }
};