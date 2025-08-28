class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (n <= 1) {
            return grid;
        }

        for (int i = 0; i < n; ++i) {
            vector<int> diagonal_elements;
            for (int r = i, c = 0; r < n && c < n; ++r, ++c) {
                diagonal_elements.push_back(grid[r][c]);
            }
            
            sort(diagonal_elements.rbegin(), diagonal_elements.rend());
            
            int k = 0;
            for (int r = i, c = 0; r < n && c < n; ++r, ++c) {
                grid[r][c] = diagonal_elements[k++];
            }
        }

        for (int j = 1; j < n; ++j) {
            vector<int> diagonal_elements;
            for (int r = 0, c = j; r < n && c < n; ++r, ++c) {
                diagonal_elements.push_back(grid[r][c]);
            }

            sort(diagonal_elements.begin(), diagonal_elements.end());

            int k = 0;
            for (int r = 0, c = j; r < n && c < n; ++r, ++c) {
                grid[r][c] = diagonal_elements[k++];
            }
        }
        
        return grid;
    }
};