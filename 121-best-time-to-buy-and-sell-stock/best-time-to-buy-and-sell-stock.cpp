class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxpo = 0;
        int minnum = INT_MAX;
        for(int i=0;i<n;i++){
            minnum = min(minnum,prices[i]);
            maxpo = max(maxpo,prices[i]-minnum);
        }
        return maxpo;
        
    }
    
};