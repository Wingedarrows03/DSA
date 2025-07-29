class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // Step 1: Clean the string (only lowercase alphanumeric)
        for (char c : s) {
            if (isalnum(c)) {
                cleaned += tolower(c);
            }
        }

        // Step 2: Reverse the cleaned string using a vector<char>
        vector<char> reversed;
        for (int i = cleaned.size() - 1; i >= 0; --i) {
            reversed.push_back(cleaned[i]);
        }

        // Step 3: Convert vector<char> to string
        string reversedStr(reversed.begin(), reversed.end());

        // Step 4: Compare original cleaned string with reversed string
        return cleaned == reversedStr;
    }
};
