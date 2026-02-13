class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int minlen = INT_MAX;
        int right = 0;

        while (right < n) {
            sum += nums[right];

            while (sum >= target) {
                minlen = min(minlen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        if (minlen == INT_MAX) {
            return 0;
        }
        return minlen;
    }
};
