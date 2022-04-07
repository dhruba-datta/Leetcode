class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size(), ans, count = 0;
        if(n == 1) return stones[0];
        
        while(count != n-1){
            sort(stones.begin(), stones.end());
            stones[n-1] = stones[n-1] - stones[n-2];
            stones[n-2] = 0;
            count++;
        }
        return stones[n-1];
    }
};