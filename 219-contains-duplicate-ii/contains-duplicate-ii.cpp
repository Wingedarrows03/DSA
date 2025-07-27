#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;   // value -> last index seen
        for (int i = 0; i < (int)nums.size(); ++i) {
            auto it = lastIndex.find(nums[i]);
            if (it != lastIndex.end() && i - it->second <= k)
                return true;
            lastIndex[nums[i]] = i;          // update last seen index
        }
        return false;
    }
};
