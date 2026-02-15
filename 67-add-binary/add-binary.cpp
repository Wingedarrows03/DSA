#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop until both strings are processed and no carry remains
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add the bit from string a if available
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Add the bit from string b if available
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // The new bit is sum % 2 (either 0 or 1)
            result += to_string(sum % 2);

            // The new carry is sum / 2
            carry = sum / 2;
        }

        // The result was constructed backwards, so reverse it
        reverse(result.begin(), result.end());

        return result;
    }
};