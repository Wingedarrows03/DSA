class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> gaps(n + 1);
        
        // Compute initial gaps
        gaps[0] = startTime[0];
        for (int i = 1; i < n; ++i) {
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        gaps[n] = eventTime - endTime[n - 1];
        
        // Sliding window of size k+1 over gaps
        long long maxGap = 0, windowSum = 0;
        for (int i = 0; i <= n; ++i) {
            windowSum += gaps[i];
            if (i > k) windowSum -= gaps[i - k - 1];
            if (i >= k) maxGap = max(maxGap, windowSum);
        }
        return (int)maxGap;
    }
};
