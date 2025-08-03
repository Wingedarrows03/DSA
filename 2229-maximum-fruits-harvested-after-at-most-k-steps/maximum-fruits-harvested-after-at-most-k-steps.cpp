class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        
        // --- Step 1: Create a prefix sum array for the fruits data ---
        // This allows for O(1) calculation of the sum of fruits in any range.
        // The prefixSum array will store the cumulative sum of fruits up to a certain index.
        std::vector<long long> prefixSum(fruits.size() + 1, 0);
        for (int i = 0; i < fruits.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + fruits[i][1];
        }

        long long max_fruits = 0;
        int left = 0;
        
        // --- Step 2: Use a sliding window with two pointers (left and right) ---
        // 'right' expands the window, and 'left' shrinks it.
        // The 'right' pointer iterates through all possible rightmost fruits to collect.
        for (int right = 0; right < fruits.size(); ++right) {
            
            // The positions of the current window's endpoints.
            int right_pos = fruits[right][0];
            
            // 'left' pointer logic:
            // We need to find the leftmost fruit 'fruits[left]' such that
            // the total steps to collect fruits in the range [fruits[left], fruits[right]]
            // is less than or equal to k.
            // The 'while' loop shrinks the window from the left if the steps exceed 'k'.
            while (left <= right) {
                int left_pos = fruits[left][0];
                long long steps = 0;
                
                // Calculate the total steps based on the path.
                if (startPos >= left_pos && startPos <= right_pos) {
                    // Scenario 1: startPos is inside the range [left_pos, right_pos]
                    // Path 1 (go right then left): (right_pos - startPos) + (right_pos - left_pos)
                    // Path 2 (go left then right): (startPos - left_pos) + (right_pos - left_pos)
                    steps = std::min(2 * (right_pos - startPos) + (startPos - left_pos),
                                   2 * (startPos - left_pos) + (right_pos - startPos));
                } else if (startPos < left_pos) {
                    // Scenario 2: startPos is to the left of the range
                    // We must move right to collect the fruits.
                    steps = right_pos - startPos;
                } else { // startPos > right_pos
                    // Scenario 3: startPos is to the right of the range
                    // We must move left to collect the fruits.
                    steps = startPos - left_pos;
                }

                if (steps <= k) {
                    // If the steps are valid, we can update the maximum fruits found so far.
                    // The 'while' loop can now be broken because any further expansion of 'right' 
                    // will maintain this valid 'left', or a new 'left' will be found.
                    break;
                }
                
                // If the steps exceed 'k', shrink the window by moving the left pointer.
                left++;
            }
            
            // After finding a valid 'left' for the current 'right', calculate the fruits.
            // Check if the window is valid (left <= right).
            if (left <= right) {
                long long current_fruits = prefixSum[right + 1] - prefixSum[left];
                max_fruits = std::max(max_fruits, current_fruits);
            }
        }
        
        return max_fruits;
    }
};
