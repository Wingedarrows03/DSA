class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;
        
        for (int i = 0; i < 26; ++i) {
            char c = 'a' + i;
            
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                maxVowelFreq = max(maxVowelFreq, freq[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, freq[i]);
            }
        }
        
        return maxVowelFreq + maxConsonantFreq;
    }
};