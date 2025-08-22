#include <vector>
#include <algorithm> // Required for std::min and std::max

class Solution {
public:
    /**
     * @brief Finds the minimum area of a rectangle that encloses all the 1's in a binary grid.
     * @param grid A 2D vector of integers representing the binary grid.
     * @return The minimum area of the enclosing rectangle.
     */
    int minimumArea(std::vector<std::vector<int>>& grid) {
        // Get the dimensions of the grid
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize boundary coordinates
        // We set min values to the largest possible and max values to the smallest possible
        // so that the first '1' found will correctly set the initial boundaries.
        int min_row = rows;
        int max_row = -1;
        int min_col = cols;
        int max_col = -1;

        // Iterate through each cell of the grid to find the outermost 1's
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    // Update the top boundary
                    min_row = std::min(min_row, i);
                    // Update the bottom boundary
                    max_row = std::max(max_row, i);
                    // Update the left boundary
                    min_col = std::min(min_col, j);
                    // Update the right boundary
                    max_col = std::max(max_col, j);
                }
            }
        }

        // The problem constraints guarantee at least one '1' is present,
        // so we don't need to handle the case where no 1's are found.

        // Calculate the height and width of the bounding rectangle.
        // We add 1 because the dimensions are inclusive. For example, if min_row = 2 and max_row = 4,
        // the rows involved are 2, 3, and 4, which is a height of 3 (4 - 2 + 1).
        int height = max_row - min_row + 1;
        int width = max_col - min_col + 1;

        // The minimum area is the product of the height and width.
        return height * width;
    }
};