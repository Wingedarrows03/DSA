#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // k is 1-based, convert to 0-based for easier processing
        k--;
        
        int shift = 0; // Tracks the total character shift for the k-th position
        
        // Process operations from right to left
        for (int i = operations.size() - 1; i >= 0; i--) {
            // Only compute segment_length for i < 47, as k <= 10^14 ≈ 2^46.5
            if (i < 47) {
                long long segment_length = 1LL << i; // Length of first half after i-th operation
                if (k >= segment_length) { // If k is in the second half
                    k -= segment_length; // Map to corresponding position in first half
                    if (operations[i] == 1) {
                        shift++; // Increment shift for type-1 operation
                    }
                }
            }
            // For i >= 47, k <= 10^14 is always in the first half (since 2^47 > 10^14)
            // No need to adjust k or shift, as the first half is identical to the previous string
        }
        
        // Return the character: 'a' shifted by the total shift amount
        return 'a' + (shift % 26);
    }
};