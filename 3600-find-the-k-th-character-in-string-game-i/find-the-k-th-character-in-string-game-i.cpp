class Solution {
public:
    char kthCharacter(int k) {
        // Use k-1 to convert to 0-based index
        long long num = k - 1;
        int val = 0;
        // Count the number of 1's in the binary representation of k-1
        while (num > 0) {
            if (num & 1) {
                val++; // Increment for each 1 bit
            }
            num >>= 1; // Right shift to process next bit
        }
        // Return 'a' plus the number of increments (mod 26)
        return 'a' + (val % 26);
    }
};