class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int l = 0;
        int r = 1;
        while(r<n){
            if (nums[l]==nums[r]){
                count++;
            }
            else{
                count = 1;
            }
            if (count <= 2){
                l++;
                nums[l] = nums[r];

            }
            
            r++;
        }
        return l+1;

    }
};