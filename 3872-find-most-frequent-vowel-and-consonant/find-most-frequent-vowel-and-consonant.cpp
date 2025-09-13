class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        unordered_map<char, int> mpp; // fixed typo

        // Count frequency of each character
        for (char c : s) {
            mpp[c]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;

        // Find max frequency for vowels and consonants
        for (auto &p : mpp) {
            char c = p.first;
            int freq = p.second;

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowel = max(maxVowel, freq);
            } else {
                maxConsonant = max(maxConsonant, freq);
            }
        }

        return maxVowel + maxConsonant;
    }
};
