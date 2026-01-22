class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int i = n1 - 1;   // pointer for s
        int skip1 = 0;    // skipper counter for s

        int j = n2 - 1;   // pointer for t
        int skip2 = 0;    // skipper counter for t

        while (i >= 0 || j >= 0) {

            // process string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skip1++;
                    i--;
                }
                else if (skip1 > 0) {
                    skip1--;
                    i--;
                }
                else {
                    break;
                }
            }

            // process string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skip2++;
                    j--;
                }
                else if (skip2 > 0) {
                    skip2--;
                    j--;
                }
                else {
                    break;
                }
            }

            // compare current valid characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            }
            else {
                if (i >= 0 || j >= 0) return false;
            }

            // move both pointers
            i--;
            j--;
        }

        return true;
    }
};
