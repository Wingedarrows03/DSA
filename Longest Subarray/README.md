class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0; // Initialize maximum length
        
        for (int i = 0; i < n; i++) { // Starting index
            long long s = 0; // Subarray sum
            for (int j = i; j < n; j++) { // Ending index
                s += nums[j]; // Add current element to sum
                
                if (s == k) {
                    len = max(len, j - i + 1); // Update max length
                }
            }
        }
        
        return len;
    }
};
