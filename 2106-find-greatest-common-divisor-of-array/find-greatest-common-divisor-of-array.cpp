#include <vector>
#include <climits> // for INT_MIN and INT_MAX

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = INT_MAX;
        int largest = INT_MIN;
        
        // Find the smallest and largest numbers in the array
        for(int num : nums) {
            if(num < smallest) smallest = num;
            if(num > largest) largest = num;
        }
        
        // Find GCD of smallest and largest
        return gcd(smallest, largest);
    }
    

    // Helper function to compute GCD using Euclidean algorithm
    int gcd(int a, int b) {
        while(b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
