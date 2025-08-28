class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        // 0 0 1 2 3 4 5 6 7 8 9
        int i = 1;
        int prev = nums[0], count = 1, mx = 1;
        while (i < nums.size()) {
            while (i < nums.size() && prev == nums[i]) {
                i++;
            }
            if (i < nums.size() && nums[i] - 1 == prev) count++;
            else count = 1;
            
            prev = nums[i];
            mx = max(mx, count);
        }

        return mx;

    }
};