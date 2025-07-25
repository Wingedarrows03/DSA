class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0; // Use 0 instead of INT_MIN to handle empty cases
        
        for (int i = 0; i < n; i++) {
            unordered_set<int> uniqueElements;
            int currentSum = 0;
            for (int j = i; j < n; j++) {
                if (uniqueElements.find(nums[j]) == uniqueElements.end()) {
                    uniqueElements.insert(nums[j]);
                    if (nums[j] > 0) { // Only include positive numbers
                        currentSum += nums[j];
                    }
                    result = max(result, currentSum);
                }
            }
        }
        
        return result == 0 ? *max_element(nums.begin(), nums.end()) : result;
    }
};