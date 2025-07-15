class Solution {
public:
    bool isValid(string word) {
        // Check minimum length of 3 characters
        if (word.length() < 3) {
            return false;
        }
        
        // Define vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        // Initialize flags for vowel and consonant
        bool hasVowel = false;
        bool hasConsonant = false;
        
        // Check each character
        for (char c : word) {
            // Check if character is alphanumeric
            if (!isalnum(c)) {
                return false;
            }
            // If it's a letter, check for vowel or consonant
            if (isalpha(c)) {
                if (vowels.count(c)) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        
        // Return true only if both vowel and consonant are present
        return hasVowel && hasConsonant;
    }
};