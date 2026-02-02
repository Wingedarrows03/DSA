class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int right = 0;
        int minlen = INT_MAX;
        while ( right < n){
            sum += nums[right];

            while (sum >= target){
                minlen = min(minlen,1+right-left);
                sum -= nums[left];
                left ++;
            }
            right ++;
        }
        return (minlen == INT_MAX) ? 0 : minlen;


    }
};