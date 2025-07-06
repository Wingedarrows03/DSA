class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX; // Track minimum price seen so far
        int maxProfit = 0;     // Track maximum profit possible
        
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price; // Update minimum price
            } else {
                maxProfit = max(maxProfit, price - minPrice); // Update max profit if current profit is higher
            }
        }
        
        return maxProfit;
    }
};