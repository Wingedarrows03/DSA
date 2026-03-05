class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0; // left pointer for 0s
        int right = n-1; // right pointer for 2s
        int mid = 0; // scanner pointer

        while( mid <= right){
            // for 0s 
            if(nums[mid] == 0){
                swap(nums[left],nums[mid]); //swap it with left
                left ++; //left pointer will increase 
                mid ++; //mid pointer will increase as well 
            }

            //for 2s
            else if (nums[mid] == 2){
                swap(nums[right],nums[mid]); //swap it with right
                right --;
            }

            //for 1s
            else {
                mid ++;
            }


        }
    }
};