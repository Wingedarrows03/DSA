class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1000000007;
        
        // dp[i] = number of ways to make sum i
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: one way to make sum 0 (empty set)
        
        // Try each positive integer starting from 1
        for (int i = 1; ; i++) {
            int power = pow(i, x);
            
            // If i^x > n, we can stop since all further powers will be even larger
            if (power > n) break;
            
            // Update dp array from right to left to avoid using updated values
            // This ensures we don't use the same number multiple times
            for (int sum = n; sum >= power; sum--) {
                dp[sum] = (dp[sum] + dp[sum - power]) % MOD;
            }
        }
        
        return dp[n];
    }
};