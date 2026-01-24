class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                // Option 1: skip left character
                int l1 = l + 1, r1 = r;
                while (l1 < r1 && s[l1] == s[r1]) {
                    l1++;
                    r1--;
                }

                // Option 2: skip right character
                int l2 = l, r2 = r - 1;
                while (l2 < r2 && s[l2] == s[r2]) {
                    l2++;
                    r2--;
                }

                // if either option forms a palindrome
                return (l1 >= r1) || (l2 >= r2);
            }
        }
        return true;
    }
};
