class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0; // for 0s
        int right = n-1; // for 2s
        int mid = 0; // scanner

        while(mid <= right){
            if (nums[mid]== 0){
                swap(nums[left],nums[mid]);
                mid ++;
                left++;
            }

            else if(nums[mid]==1){
                    mid++;
                }

            else{
                    swap(nums[right],nums[mid]);
                    right --;

                }

            

        }

    }
};