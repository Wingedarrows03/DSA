class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;          // ❌ you started with 0
                                 // ✅ first element is already counted once
        int l = 0;
        int r = 1;

        while (r < n) {
            if (nums[l] == nums[r]) {
                count++;        // same number, increase count
            } else {
                count = 1;      // ❌ you forgot to reset count
                                 // ✅ new number → reset counter
            }

            if (count <= 2) {   // ❌ you wrote (count = 2)
                                 // ✅ must be comparison and <= 2
                l++;
                nums[l] = nums[r]; // ❌ earlier you swapped sides
                                   // ✅ always write at l
            }

            r++;                // ❌ r must move EVERY iteration
        }

        return l + 1;           // ✅ correct return
    }
};
