class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // Slow pointer for placing unique elements
        
        for (int j = 1; j < n; j++) { // Fast pointer to scan the array
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;
    }
};