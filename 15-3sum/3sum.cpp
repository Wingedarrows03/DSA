class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result; //hold the result 
        sort(nums.begin(),nums.end()); //sorting to handel duplicates easily 

        int i = 0; //anchor pointer

        while(i <= n-3) // leaving enough space for 2 other pointers (i <= n-3)
        { 
            if(i>0 && nums[i] == nums[i-1])// handeling duplicates (looking backwards)
            {
                i ++;
                continue;
            }
            int left = i+1; //left pointer
            int right = n-1; //right pointer

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right]; //sum 
                // sum is less than target
                if ( sum < 0){
                    left ++;
                }

                //sum i smore than target 
                else if(sum > 0){
                    right --;
                }

                //hit the target 
                else{
                    result.push_back({nums[i],nums[left],nums[right]});

                //handeling duplicates for left & right pointers
                //using internal breaks
                while(left < right && nums[right] == nums[right-1]){
                    right --;
                    continue;
                }

                while(left < right && nums[left] == nums[left+1]){
                    left ++;
                    continue;
                }
                //pointers must move 
                left++;
                right --;

               }

            }
            i++; // move the anchor pointer 
        }
        return result; //final answer
        
    }
};