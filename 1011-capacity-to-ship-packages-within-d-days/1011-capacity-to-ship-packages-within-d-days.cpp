class Solution {
public:
    int shipWithinDays(vector<int>& w, int day) {
        int ans = INT_MIN, low = INT_MIN, high = 0, n = w.size();
        
        for(auto x:w){
            high += x;
            low = max(x, low);
        }
        
        while(low < high){
            int mid = low + (high-low) / 2;
            int temp = 0, d = 1;
            
            for(int i=0; i<n; i++){
                if(temp + w[i] > mid){
                    temp = 0;
                    d++;
                }
                temp += w[i];
            }
            
            if(d > day) low = mid+1;
            else high = mid;
            
        }
        return low;
    }
};