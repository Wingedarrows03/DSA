#include <vector>
#include <algorithm>

class Solution {
public:
    int countSquares(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        int totalSquares = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    totalSquares += dp[i][j];
                }
            }
        }

        return totalSquares;
    }
};