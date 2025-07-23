class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;
        string first, second;
        
        // Determine which substring to remove first based on points
        if (x >= y) {
            first = "ab";
            second = "ba";
        } else {
            first = "ba";
            second = "ab";
        }
        
        // First pass: Remove higher-point substring
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == first[0] && c == first[1]) {
                stack.pop_back();
                totalPoints += (first == "ab" ? x : y);
            } else {
                stack.push_back(c);
            }
        }
        
        // Convert remaining stack to string for second pass
        string remaining(stack.begin(), stack.end());
        
        // Second pass: Remove the other substring
        stack.clear();
        for (char c : remaining) {
            if (!stack.empty() && stack.back() == second[0] && c == second[1]) {
                stack.pop_back();
                totalPoints += (second == "ab" ? x : y);
            } else {
                stack.push_back(c);
            }
        }
        
        return totalPoints;
    }
};