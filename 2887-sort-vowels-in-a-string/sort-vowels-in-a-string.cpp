class Solution {
public:
    std::string sortVowels(std::string s) {
        std::string vowels;
        for (char c : s) {
            if (std::string("aeiouAEIOU").find(c) != std::string::npos) {
                vowels.push_back(c);
            }
        }
        
        std::sort(vowels.begin(), vowels.end());
        
        int vowelIndex = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (std::string("aeiouAEIOU").find(s[i]) != std::string::npos) {
                s[i] = vowels[vowelIndex++];
            }
        }
        
        return s;
    }
};