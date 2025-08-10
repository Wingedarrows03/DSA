class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end()); // removes duplicates & sorts
        if (s.size() < 3) // less than 3 unique
            return *s.rbegin(); // largest
        return *next(s.rbegin(), 2); // 3rd largest
    }
};
