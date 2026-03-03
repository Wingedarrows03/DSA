class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0; // pointers for 0s
        int right = n - 1; // pointers for 1s
        int mid = 0; // pointers for scouting 

        while(mid <= right){
            // for 0s
            if ( nums[mid] == 0){
                swap(nums[left],nums[mid]); // swap it with left
                left ++; // left will increase
                mid ++; // mid will increase as well 
            }

            //for 2s
            else if ( nums[mid] == 2){
                swap(nums[right],nums[mid]); // swap the mid with right
                right --;
                
            }

            //for 1s
            else{
                mid ++;
            }


        }
        
    }
};