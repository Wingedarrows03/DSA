class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Step 1: Store the last k elements
        vector<int> temp;
        for (int i = n - k; i < n; i++) {
            temp.push_back(nums[i]);
        }

        // Step 2: Shift the first n - k elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: Copy the k elements from temp to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
