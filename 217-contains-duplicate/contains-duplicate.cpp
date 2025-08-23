class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 0;
        unordered_set <int> mp;
        for ( int num: nums){
            if( mp.count(num)){
            return true;
        }
        mp.insert(num);
        }
        return false;
    
    }
  
};