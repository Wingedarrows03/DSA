class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            if (nums[l] * nums[l] > nums[r] * nums[r]) {
                res.push_back(nums[l] * nums[l]);
                l++;
            } else {
                res.push_back(nums[r] * nums[r]);
                r--;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
