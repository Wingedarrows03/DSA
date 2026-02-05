class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;

        unordered_map<int, int> freq; // frequency map

        while (right < n) {
            // expand window
            freq[fruits[right]]++;

            // shrink window if more than 2 fruit types
            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }

            // update answer
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};
