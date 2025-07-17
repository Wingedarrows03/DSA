class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[r] stores the max length of subsequence with adjacent sum r (mod k)
        // For each r, we store a map of {last element mod k -> max length}
        vector<unordered_map<int, int>> dp(k);
        int maxLen = 1; // Minimum length is 1 (single element)

        // Process each element
        for (int i = 0; i < n; ++i) {
            int curr = nums[i] % k;

            // Try extending subsequences for each remainder r
            for (int r = 0; r < k; ++r) {
                // To have (prev + curr) % k == r, prev % k = (r - curr + k) % k
                int prev = (r - curr + k) % k;

                // If we have a subsequence with remainder r ending with prev
                if (dp[r].find(prev) != dp[r].end()) {
                    dp[r][curr] = max(dp[r][curr], dp[r][prev] + 1);
                } else {
                    // Start a new subsequence with curr (length 1)
                    dp[r][curr] = max(dp[r][curr], 1);
                }

                // Update maxLen
                maxLen = max(maxLen, dp[r][curr]);
            }
        }

        return maxLen;
    }
};