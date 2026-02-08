class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> rev;
        while (left <= right){
            if ( nums[left] * nums[left] > nums[right] * nums[right] ){
                rev.push_back(nums[left]*nums[left]);
                left ++;
            }
            else {
                rev.push_back(nums[right]*nums[right]);
                right --;
            }

        }
        reverse(rev.begin(),rev.end());
        return rev;
    }
};