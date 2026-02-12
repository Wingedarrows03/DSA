class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long sum = 0;
        long long maxsum = 0;

        unordered_map<int,int> mp;

        while( right < k){
            sum += nums[right];
            mp[nums[right]] ++;
            right ++;
            if ( mp.size() == k){
                maxsum = sum;
            }
        }

        while( right < n){
            sum += nums[right];
            mp[nums[right]] ++;

            sum -= nums[left];
            mp[nums[left]] --;

            if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
            }

            right ++;
            left ++;

            if(mp.size() == k){
                maxsum = max(sum,maxsum);
            }

        }
        return maxsum;
    }
};