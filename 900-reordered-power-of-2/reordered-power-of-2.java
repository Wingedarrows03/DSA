class Solution {
    public boolean reorderedPowerOf2(int n) {
        // Get digit frequency of input number
        int[] targetFreq = getDigitFrequency(n);
        
        // Check all powers of 2 up to 10^9
        for (int i = 0; i < 32; i++) {
            int powerOf2 = 1 << i; // 2^i
            if (powerOf2 > 1000000000) break; // Exceeds 10^9
            
            int[] powerFreq = getDigitFrequency(powerOf2);
            
            // Compare digit frequencies
            if (arraysEqual(targetFreq, powerFreq)) {
                return true;
            }
        }
        
        return false;
    }
    
    // Helper method to get frequency of each digit (0-9)
    private int[] getDigitFrequency(int num) {
        int[] freq = new int[10];
        while (num > 0) {
            freq[num % 10]++;
            num /= 10;
        }
        return freq;
    }
    
    // Helper method to compare two frequency arrays
    private boolean arraysEqual(int[] arr1, int[] arr2) {
        for (int i = 0; i < 10; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
}