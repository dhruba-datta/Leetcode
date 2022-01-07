class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int ans= INT_MIN;
        int start=0, end=n-1;
        
        while(start<end){
            int a= min(height[start], height[end]) * (end-start);
            ans = max(ans, a);
            
            if(height[start] > height[end])
                end--;
            else
                start++;
        }
        
        return ans;
    }
};