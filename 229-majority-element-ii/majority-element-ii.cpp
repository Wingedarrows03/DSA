class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it: mpp){
            if(it.second > n/3)
            {
                result.push_back(it.first);
            }
        }
        return result;
    }
};