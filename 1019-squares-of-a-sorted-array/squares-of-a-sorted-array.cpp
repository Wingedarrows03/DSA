class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> rev; // creating a result vector
        int left = 0; //left pointer 
        int right = n - 1; //right pointer

        while ( left <= right)
        {
            // if left sqr is more than righ
            if ( nums[left]* nums[left] > nums[right]* nums[right]){
                rev.push_back(nums[left]*nums[left]); // pushing left sqr
                left ++;// moving the left pointer fwd
            }

            // when right sqr is more than left 
            else {
            rev .push_back(nums[right] * nums[right]); //pushing right sqr
            right --;  // moving right pointer backwards

            } 

        }
        reverse(rev.begin(),rev.end()); // reversing the rev array
        return rev; // output of answer 
        
    }
};