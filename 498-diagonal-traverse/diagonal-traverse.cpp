#include <vector>

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) {
            return {};
        }

        int m = mat.size();
        int n = mat[0].size();
        
        std::vector<int> result;
        result.reserve(m * n);

        int row = 0, col = 0;
        bool going_up = true;

        while (result.size() < m * n) {
            result.push_back(mat[row][col]);

            if (going_up) {
                if (col == n - 1) {
                    row++;
                    going_up = false;
                } else if (row == 0) {
                    col++;
                    going_up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {
                    col++;
                    going_up = true;
                } else if (col == 0) {
                    row++;
                    going_up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }
        return result;
    }
};