class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        // Edge case
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();      // length of each word
        int wordCount = words.size();         // total number of words
        int totalLen = wordLen * wordCount;   // total length of valid substring
        int n = s.length();

        // Step 1: Build frequency map of given words
        unordered_map<string, int> target;
        for (string &w : words) {
            target[w]++;
        }

        // Step 2: We try all possible alignments (0 to wordLen-1)
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;        // start of sliding window
            int right = offset;       // end of sliding window
            int count = 0;            // number of valid words in window
            unordered_map<string, int> window;  // frequency inside current window

            // Slide window in chunks of wordLen
            while (right + wordLen <= n) {

                // Extract word of size wordLen
                string word = s.substr(right, wordLen);
                right += wordLen;  // move right pointer in jumps

                // Case 1: Word is valid (exists in target map)
                if (target.count(word)) {

                    window[word]++;  // add word to window
                    count++;

                    // If word frequency exceeds allowed frequency,
                    // shrink window from left
                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If we matched all words
                    if (count == wordCount) {
                        result.push_back(left);
                    }

                } 
                // Case 2: Word not valid → reset window
                else {
                    window.clear();
                    count = 0;
                    left = right;   // move left to next position
                }
            }
        }

        return result;
    }
};
