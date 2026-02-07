class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long sum = 0;
        long long maxsum = 0;

        unordered_map<int, int> freq;

        while (right < n) {
            // expand window
            sum += nums[right];
            freq[nums[right]]++;

            // shrink window if size exceeds k
            while (right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            // valid window: size == k and all elements distinct
            if (right - left + 1 == k && freq.size() == k) {
                maxsum = max(maxsum, sum);
            }

            right++;
        }

        return maxsum;
    }
};
