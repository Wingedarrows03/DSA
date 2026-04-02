class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        //edge case handeling - 1
        if (target < 0) return 0;

        int left = 0; // left pointer 
        int right = 0; //right pointer 
        long long sum = 0; // sum 
        int minlen = INT_MAX; // minimum length 

        for(right = 0; right <= n-1; right++){
            sum += nums[right];

            // if sum >= target
            while(sum >= target){
                minlen = min(minlen, right - left + 1); //finding the minimum
                sum -= nums[left]; // removing the oldest number 
                left ++; // left pointer will move 
            }

            
        }
        if (minlen == INT_MAX) return 0; // edge case handeling - 2
        return minlen;

    }
};