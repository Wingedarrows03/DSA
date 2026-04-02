class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        // edge case handeling
        if (k <= 1){
            return 0;
        }

        int left = 0; // left pointer 
        int right = 0; //right pointer 
        int product = 1; // product 
        int count = 0; //counter 

        for(int right = 0; right <= n-1; right++){
            product *= nums[right]; // expanding window by multilying new element 

            // when product exceeds k 
            // while is used because we need to deal with multiple elements or if was used
            while(product >= k && left <= right){
                product /= nums[left]; // oldest number is divided 
                left ++; // left pointer is moved 
            }

            count += (right - left + 1);
        }
        return count;
    }
   
};