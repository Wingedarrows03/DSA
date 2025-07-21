class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        
        for (char c : s) {
            int n = result.length();
            
            // Check if adding current character would create 3 consecutive same characters
            if (n >= 2 && result[n-1] == c && result[n-2] == c) {
                // Skip this character to avoid 3 consecutive same characters
                continue;
            }
            
            // Safe to add this character
            result += c;
        }
        
        return result;
    }
};