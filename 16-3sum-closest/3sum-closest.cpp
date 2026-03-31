class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort (nums.begin(),nums.end()); //sorting for better handeling 
        int closest = nums[0] + nums[1] + nums[2]; //comparing parameter

        int i = 0; //anchor pointer 

        while(i < n-2) // leaving enough space for left & right pointer
        {
            int left = i+1; //left pointer 
            int right = n-1; //right pointer 

            while(left < right){
            int sum = nums[i] + nums[left] + nums[right]; //sum

            //comparing distance to find the closest triplet 
            if (abs(sum - target) < (abs(closest - target))){
                closest = sum ;
            }

            // trying to reach closest to the target 
            if( sum < target){
                left ++;
            }
            else if (sum > target){
                right --;
            }
            else {
                return sum;
            }

            }
            //move the anchor pointer 
            i++;
        
        }
        //return the answer
        return closest;
         
    }
};