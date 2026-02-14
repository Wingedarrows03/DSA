class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.length();

        unordered_map<string, int> target;
        for (string &w : words) {
            target[w]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int right = i;
            int count = 0;
            unordered_map<string, int> window;

            while (right + wordLen <= n) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (target.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > target[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
