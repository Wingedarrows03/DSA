#include <string>

class Solution {
public:
    int maximum69Number (int num) {
        std::string s_num = std::to_string(num);
        
        for (char &c : s_num) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        
        return std::stoi(s_num);
    }
};