#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mpp.count(nums[i])){
               if(i - mpp[nums[i]]<=k){
                return true;
               }
            }
            mpp[nums[i]]=i;

        }
        return false;
    }
};
