class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;

        //1) edge case
        if (s.empty() || words.empty()) {
            return result;
        }

        //2) general declaration
        int n = s.size();
        int wordcount = words.size();          // total number of words
        int wordlen = words[0].length();       // number of letters in each word
        int total = wordcount * wordlen;       // total window size we are searching for

        //3) Map 1 declaration - works with words vector and provides target frequencies
        unordered_map<string, int> target;
        for (string &w : words) {
            target[w]++;
        }

        //4) Offset/pointer declaration (alignment handling)
        for (int offset = 0; offset < wordlen; offset++) {

            int right = offset;
            int left = offset;
            int count = 0;

            // map 2 declaration - works with current sliding window
            unordered_map<string, int> window;

            //5) movement in chunks (chunks are decided by wordlen)
            while (right + wordlen <= n) {

                string word = s.substr(right, wordlen); // substring extraction
                right += wordlen;                       // move right in chunk

                //5.1) If the word is valid
                if (target.count(word)) {

                    window[word]++;
                    count++;

                    //5.2) If frequency exceeds allowed, shrink window from left
                    while (window[word] > target[word]) {
                        string leftword = s.substr(left, wordlen);
                        window[leftword]--;
                        left += wordlen;
                        count--;
                    }

                    //5.3) If we matched all words
                    if (count == wordcount) {
                        result.push_back(left);
                    }
                }

                //5.4) If word is NOT valid → reset window
                else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        //6) return result
        return result;
    }
};
