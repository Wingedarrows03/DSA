#include <iostream>

#if defined(__GNUC__) || defined(__clang__)
#define popcountll __builtin_popcountll
#else
long long popcountll(long long n) {
    long long count = 0;
    while (n > 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
#endif

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long n1_ll = num1;

        for (int k = 1; k <= 64; ++k) {
            long long target = n1_ll - (long long)k * num2;
            
            if (target >= k && popcountll(target) <= k) {
                return k;
            }
        }
        
        return -1;
    }
};

