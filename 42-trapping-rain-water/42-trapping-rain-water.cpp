class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> p;
        vector<int> s(height.size(), 0);
        int h=0, ans=0;
        for(auto x:height){
            h = max(h, x);
            p.push_back(h);
        }
        h=0;
        for(int i=height.size()-1; i>=0; i--){
            h=max(h, height[i]);
            s[i] = h;
        }
        for(int i=0; i<height.size(); i++){
            ans += min(p[i],s[i])-height[i];
        }
        return ans;
    }
};