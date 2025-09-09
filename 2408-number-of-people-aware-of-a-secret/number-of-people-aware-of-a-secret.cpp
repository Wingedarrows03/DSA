#include <vector>

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long MOD = 1e9 + 7;
        std::vector<long> dp(n + 1, 0);
        dp[1] = 1;
        long sharingCount = 0;

        for (int i = 2; i <= n; ++i) {
            if (i - delay >= 1) {
                sharingCount = (sharingCount + dp[i - delay]) % MOD;
            }
            
            if (i - forget >= 1) {
                sharingCount = (sharingCount - dp[i - forget] + MOD) % MOD;
            }
            
            dp[i] = sharingCount;
        }

        long totalAware = 0;
        for (int i = n - forget + 1; i <= n; ++i) {
            totalAware = (totalAware + dp[i]) % MOD;
        }

        return static_cast<int>(totalAware);
    }
};