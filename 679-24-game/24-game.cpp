class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) {
            nums.push_back(card);
        }
        return solve(nums);
    }
    
private:
    const double EPS = 1e-6;
    
    bool solve(vector<double>& nums) {
        if (nums.size() == 1) {
            return abs(nums[0] - 24.0) < EPS;
        }
        
        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double a = nums[i], b = nums[j];
                
                // Create new array without nums[i] and nums[j]
                vector<double> remaining;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        remaining.push_back(nums[k]);
                    }
                }
                
                // Try all possible operations between a and b
                vector<double> results = {a + b, a - b, b - a, a * b};
                
                // Division operations (avoid division by zero)
                if (abs(b) > EPS) results.push_back(a / b);
                if (abs(a) > EPS) results.push_back(b / a);
                
                // Try each result
                for (double result : results) {
                    remaining.push_back(result);
                    if (solve(remaining)) {
                        return true;
                    }
                    remaining.pop_back();
                }
            }
        }
        
        return false;
    }
};