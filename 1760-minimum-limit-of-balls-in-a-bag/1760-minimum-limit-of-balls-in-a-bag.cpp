class Solution {
public:
    int minimumSize(vector<int>& w, int maxOperations) {
        int ans = INT_MIN, low = 1, high = INT_MAX, n = w.size();
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            int o = maxOperations;
            for(int i=0; i<w.size(); i++){
                o -= w[i]/mid;
                if(w[i] % mid == 0) o++;
            }
            
            if(o >= 0){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
        return ans;
    }
};