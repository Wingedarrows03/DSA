class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;

        long long windowsum = 0;

        // Build first window
        while (right < k) {
            windowsum += nums[right];
            right++;
        }

        long long maxsum = windowsum;

        // Slide the window
        while (right < n) {
            windowsum += nums[right];
            windowsum -= nums[left];
            right++;
            left++;

            maxsum = max(maxsum, windowsum);
        }

        return (double)maxsum / k;
    }
};
