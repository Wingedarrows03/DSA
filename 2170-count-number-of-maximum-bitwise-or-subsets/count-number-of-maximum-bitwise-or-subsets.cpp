class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        // Find the maximum possible OR (OR of all elements)
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        // Count subsets with maximum OR using backtracking
        return countSubsets(nums, 0, 0, maxOr);
    }
    
private:
    int countSubsets(vector<int>& nums, int index, int currentOr, int targetOr) {
        // Base case: we've considered all elements
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }
        
        // Two choices: include current element or exclude it
        int count = 0;
        
        // Choice 1: Include current element
        count += countSubsets(nums, index + 1, currentOr | nums[index], targetOr);
        
        // Choice 2: Exclude current element
        count += countSubsets(nums, index + 1, currentOr, targetOr);
        
        return count;
    }
};

// Alternative optimized solution using memoization
class SolutionOptimized {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int num : nums) {
            maxOr |= num;
        }
        
        unordered_map<string, int> memo;
        return countSubsetsWithMemo(nums, 0, 0, maxOr, memo);
    }
    
private:
    int countSubsetsWithMemo(vector<int>& nums, int index, int currentOr, 
                            int targetOr, unordered_map<string, int>& memo) {
        if (index == nums.size()) {
            return (currentOr == targetOr) ? 1 : 0;
        }
        
        string key = to_string(index) + "," + to_string(currentOr);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int count = 0;
        count += countSubsetsWithMemo(nums, index + 1, currentOr | nums[index], targetOr, memo);
        count += countSubsetsWithMemo(nums, index + 1, currentOr, targetOr, memo);
        
        memo[key] = count;
        return count;
    }
};