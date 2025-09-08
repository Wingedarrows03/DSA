#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; a++) {
            int b = n - a;
            if (std::to_string(a).find('0') == std::string::npos && 
                std::to_string(b).find('0') == std::string::npos) {
                return {a, b};
            }
        }
        return {};
    }
};