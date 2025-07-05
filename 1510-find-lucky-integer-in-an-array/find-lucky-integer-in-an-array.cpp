class Solution {
public:
    int findLucky(vector<int>& arr) {
        // Step 1: Create a frequency array (size 501 to handle numbers 1 to 500)
        vector<int> freq(501, 0); // Initialize with zeros
        for (int num : arr) {
            freq[num]++; // Count frequency of each number
        }
        
        // Step 2: Find lucky numbers (frequency equals value)
        int max_lucky = -1;
        for (int i = 1; i <= 500; i++) {
            if (i == freq[i]) { // Check if number equals its frequency
                max_lucky = max(max_lucky, i); // Update largest lucky number
            }
        }
        
        // Step 3: Return the largest lucky number or -1
        return max_lucky;
    }
};