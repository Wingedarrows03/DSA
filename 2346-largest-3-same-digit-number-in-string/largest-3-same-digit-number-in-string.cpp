#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string sub = num.substr(i, 3);
                if (sub > ans) ans = sub; // lexicographic comparison works for digits
            }
        }
        return ans;
    }
};
