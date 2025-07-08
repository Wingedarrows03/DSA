class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // Sort events by start day
        sort(events.begin(), events.end());
        
        int n = events.size();
        // Precompute next non-overlapping event index
        vector<int> next(n, n);
        for (int i = 0; i < n; ++i) {
            int lo = i + 1, hi = n - 1, endDay = events[i][1];
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (events[mid][0] > endDay) {
                    next[i] = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        // dp[i][j] = max value considering events from index i with j events left
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Fill DP table bottom-up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                // Skip current event
                dp[i][j] = dp[i + 1][j];
                
                // Take current event if j > 0
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], events[i][2] + dp[next[i]][j - 1]);
                }
            }
        }
        
        return dp[0][k];
    }
};