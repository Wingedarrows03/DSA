class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0; // ✅ Declare and initialize

        for (int i = n - 1; i >= 0; i--) { // ✅ Decrement properly
            count++;
            if (count == k) {
                return nums[i];
            }
        }
        return -1; // in case k is invalid
    }
};