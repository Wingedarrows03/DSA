class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n1 = nums.size();
        vector<int> even;
        unordered_map<int, int> mpp;

        // Step 1: Extract even numbers
        for (int i = 0; i < n1; i++) {
            if (nums[i] % 2 == 0) {
                even.push_back(nums[i]);
            }
        }

        // Step 2: Count frequency (AFTER filling even vector)
        int n2 = even.size();
        for (int j = 0; j < n2; j++) {
            mpp[even[j]]++;
        }

        // Step 3: Find max frequency with smallest number on tie
        int max_freq = 0;
        int ans = -1;

        for (auto it : mpp) {
            if (it.second > max_freq) {
                max_freq = it.second;
                ans = it.first;
            } else if (it.second == max_freq && it.first < ans) {
                ans = it.first;
            }
        }

        return ans;
    }
};
