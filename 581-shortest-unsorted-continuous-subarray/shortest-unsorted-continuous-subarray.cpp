class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxval = INT_MIN; //stores maxvalue
        int minval = INT_MAX; //stores minimum value

        int start = -1; //placeholder value to meet the formula
        int end = -2; //placeholder value to meet the formula 

        int left = 0; //left pointer 
        int right  = n-1; //right pointer 

        //finding the rightmost out of order element (left - right)
        while(left <= n-1){
            if(nums[left]<maxval){
                end = left;// end of the subarray
            }
            else{
              maxval = nums[left]; // new max val will be found 
            }
            left ++;
        }

        //finding the leftmost out of order element (right - left)
        while(right >= 0){
            if(nums[right]>minval){
                start = right; //start of the subarray
            }
            else{
                minval = nums[right]; // new min value
            }
            right --;
        }
        return end - start + 1; // final answer
    }
};