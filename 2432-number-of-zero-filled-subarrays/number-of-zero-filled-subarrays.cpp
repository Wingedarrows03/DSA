class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long totalSubarrays = 0;
        long long currentStreak = 0;
        
        for (int num : nums) {
            if (num == 0) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }
            totalSubarrays += currentStreak;
        }
        
        return totalSubarrays;
    }
};