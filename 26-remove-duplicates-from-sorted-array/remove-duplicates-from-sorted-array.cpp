class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();      // ✅ Declare n
        if (n == 0) return 0;     // ✅ Handle empty input
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] != nums[j]) {  // ✅ Use nums, not arr
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};
