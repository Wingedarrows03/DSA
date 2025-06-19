class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i =0; i<n;i++){
            if(nums[i] != i){
                return i;
            }
        }
        return n;
    }
};