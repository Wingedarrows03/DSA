class Solution {
public:
    bool isPalindrome(string s) {
        // Create a cleaned string with only alphanumeric characters in lowercase
        string cleaned = "";
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }
        
        // Compare string with its reverse using two pointers
        int left = 0;
        int right = cleaned.length() - 1;
        
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};