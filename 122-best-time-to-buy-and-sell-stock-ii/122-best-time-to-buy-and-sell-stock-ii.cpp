class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), profit=0;
        int mn=prices[0];
        
        for(int i=1; i<n; i++){
            if(mn<prices[i]){
                profit += prices[i]-mn;
            }
            mn = prices[i];
            
        }
        return profit;
    }
};