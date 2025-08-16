class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            int remainder = n % 3;   // take remainder in base-3 conversion
            if (remainder == 2) {
                return false;        // digit "2" means duplicate power needed
            }
            n = n/3;                  // move to next digit in base-3
        }
        return true;                 // all digits were 0 or 1
    }
};
