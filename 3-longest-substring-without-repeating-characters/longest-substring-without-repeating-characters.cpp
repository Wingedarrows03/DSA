class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;

        unordered_set<char> st; // 🔑 hash tracking

        while (right < n) {
            // If duplicate found, shrink window
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            // Add current character
            st.insert(s[right]);

            // Update answer
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};
