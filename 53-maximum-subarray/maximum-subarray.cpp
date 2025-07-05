class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN; // Tracks the maximum subarray sum
        int currentSum = 0;   // Tracks the sum of the current subarray
        
        for (int num : nums) {
            // Add current element to currentSum
            // If currentSum becomes negative, reset it to the current element
            currentSum = max(num, currentSum + num);
            // Update maxSum if currentSum is larger
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};