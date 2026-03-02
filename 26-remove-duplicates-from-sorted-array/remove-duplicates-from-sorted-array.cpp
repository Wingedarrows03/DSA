class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // we will put 2 pointer right next to each other as all the repeating numbers are next to each other 
        int n = nums.size();
        int i = 0; // first pointer 
        int j = i+1; // second pointer right next to first pointer 
        
        while ( j < n){
            if (nums[i] != nums[j]){
                i++; // first pointer will move 
                nums[i] = nums[j]; //overwriting step 
    
            }
             j++; // second pointer will move too
            
        }
        return i+1; // as i starts from 0  
        
    }
};