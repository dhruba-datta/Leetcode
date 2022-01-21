class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();  
        vector <int> left(n), right(n);
        
        int mn = prices[0], mx = prices[n-1];
        
        for(int i=1; i<n; i++){
            left[i] = max(left[i-1], prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            
            right[i] = max(right[i+1], mx-prices[i]);
            mx = max(mx, prices[i]);
        }
        
        int profit = right[0];
        
        for(int i=1; i<n; i++)
            profit = max(profit, left[i-1]+right[i]);
        
        
        return profit;
    }
};