class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {false};
        for (char c : brokenLetters) {
            broken[c - 'a'] = true;
        }

        int count = 0;
        bool word_is_broken = false;

        for (char c : text) {
            if (c == ' ') {
                if (!word_is_broken) {
                    count++;
                }
                word_is_broken = false;
            } else if (broken[c - 'a']) {
                word_is_broken = true;
            }
        }

        if (!word_is_broken) {
            count++;
        }

        return count;
    }
};