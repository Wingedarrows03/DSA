class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;

        unordered_map<char, int> lastIndex;

        while (right < n) {
            // if character already seen inside current window
            if (lastIndex.count(s[right]) && lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            // update last seen index
            lastIndex[s[right]] = right;

            // update answer
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};
