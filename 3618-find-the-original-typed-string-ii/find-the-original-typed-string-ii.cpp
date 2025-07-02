class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1000000007;
        int n = word.size();
        vector<int> lengths;
        char prev = word[0];
        int count = 1;

        // Step 1: Identify runs and their lengths
        for (int i = 1; i < n; ++i) {
            if (word[i] == prev) {
                count++;
            } else {
                lengths.push_back(count);
                prev = word[i];
                count = 1;
            }
        }
        lengths.push_back(count);
        int m = lengths.size(); // Number of runs

        // Step 2: Handle edge cases
        if (k > n) return 0; // No string can have length > n
        long long total = 1;
        for (int len : lengths) {
            total = (total * len) % MOD;
        }
        if (m >= k) return total; // All strings have length >= m >= k

        // Step 3: Initialize DP
        int max_sum = k - m; // We need sum d_i < k - m
        vector<long long> dp(max_sum, 0);
        vector<long long> ps(max_sum, 0);
        dp[0] = 1;
        ps[0] = 1;
        for (int s = 1; s < max_sum; ++s) {
            ps[s] = ps[s-1]; // Initialize prefix sum
        }

        // Step 4: Process each run
        for (int i = 0; i < m; ++i) {
            vector<long long> new_dp(max_sum, 0);
            vector<long long> new_ps(max_sum, 0);
            int max_di = lengths[i] - 1;

            for (int s = 0; s < max_sum; ++s) {
                // Compute dp[i+1][s] using prefix sums
                new_dp[s] = ps[s]; // Sum of dp[i][s-d] for d=0 to min(s, max_di)
                if (s - max_di - 1 >= 0) {
                    new_dp[s] = (new_dp[s] - ps[s - max_di - 1] + MOD) % MOD;
                }
                // Update prefix sum
                new_ps[s] = new_dp[s];
                if (s > 0) {
                    new_ps[s] = (new_ps[s] + new_ps[s-1]) % MOD;
                }
            }
            dp = move(new_dp);
            ps = move(new_ps);
        }

        // Step 5: Sum invalid solutions (sum d_i < k - m)
        long long invalid = ps[max_sum - 1];
        return (total - invalid + MOD) % MOD;
    }
};