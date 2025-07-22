class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen; // Tracks unique elements in the current window
        int maxSum = 0, currSum = 0; // Max sum and current window sum
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < n; right++) {
            // Shrink window while nums[right] is already in the set
            while (seen.find(nums[right]) != seen.end()) {
                currSum -= nums[left]; // Remove leftmost element from sum
                seen.erase(nums[left]); // Remove leftmost element from set
                left++; // Move left pointer
            }
            // Add current element to window
            seen.insert(nums[right]);
            currSum += nums[right];
            // Update max sum if current window sum is larger
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};