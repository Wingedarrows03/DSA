class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pre(n);
        vector<int> suf(n);

        pre[0]=1;
        suf[n-1]=1;

        for(int i =1;i<n;i++){
            pre[i]=nums[i-1]*pre[i-1];
        }

        for(int i = n-2;i>=0;i--){
            suf[i]=nums[i+1]*suf[i+1];
        }

        for(int i = 0;i<n;i++){
            res[i]=pre[i]*suf[i];
        }
        return res;
   
    }
};