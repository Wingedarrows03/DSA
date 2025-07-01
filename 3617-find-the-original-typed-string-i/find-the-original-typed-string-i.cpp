class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int i = 0;
        int total = 1;

        while (i < n) {
            int j = i;
            while (j < n && word[j] == word[i]) j++;
            int len = j - i;
            if (len > 1) {
                total += (len - 1);  // (len - 1) reductions possible for this group
            }
            i = j;
        }

        return total;
    }
};