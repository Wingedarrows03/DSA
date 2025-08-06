class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        // Step 1: Frequency map
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        // Step 2: Create buckets where index = frequency
        vector<vector<int>> bucket(n + 1);
        for (auto& it : mpp) {
            bucket[it.second].push_back(it.first);
        }

        // Step 3: Traverse buckets in reverse to get top K frequent elements
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};
