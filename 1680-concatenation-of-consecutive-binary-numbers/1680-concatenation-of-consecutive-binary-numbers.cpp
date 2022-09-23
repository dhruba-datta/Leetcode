class Solution {
public:
    
    int numberOfBits(int n) {
      int len = 0;
      for (int j = n; j; j >>= 1, ++len);
      return len;
    }
    
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};