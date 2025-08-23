class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = INT_MAX;
        
        // Helper function to calculate minimum rectangle area for 1's in a region
        auto getMinArea = [&](int r1, int c1, int r2, int c2) -> int {
            int minR = INT_MAX, maxR = -1, minC = INT_MAX, maxC = -1;
            bool found = false;
            
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    if (grid[i][j] == 1) {
                        found = true;
                        minR = min(minR, i);
                        maxR = max(maxR, i);
                        minC = min(minC, j);
                        maxC = max(maxC, j);
                    }
                }
            }
            
            if (!found) return 0; // No 1's in this region
            return (maxR - minR + 1) * (maxC - minC + 1);
        };
        
        // Pattern 1: Three horizontal strips
        for (int cut1 = 0; cut1 < m - 2; cut1++) {
            for (int cut2 = cut1 + 1; cut2 < m - 1; cut2++) {
                int area1 = getMinArea(0, 0, cut1, n - 1);
                int area2 = getMinArea(cut1 + 1, 0, cut2, n - 1);
                int area3 = getMinArea(cut2 + 1, 0, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 2: Three vertical strips
        for (int cut1 = 0; cut1 < n - 2; cut1++) {
            for (int cut2 = cut1 + 1; cut2 < n - 1; cut2++) {
                int area1 = getMinArea(0, 0, m - 1, cut1);
                int area2 = getMinArea(0, cut1 + 1, m - 1, cut2);
                int area3 = getMinArea(0, cut2 + 1, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 3: Top rectangle + bottom two rectangles (horizontal split then vertical)
        for (int hcut = 0; hcut < m - 1; hcut++) {
            for (int vcut = 0; vcut < n - 1; vcut++) {
                int area1 = getMinArea(0, 0, hcut, n - 1);
                int area2 = getMinArea(hcut + 1, 0, m - 1, vcut);
                int area3 = getMinArea(hcut + 1, vcut + 1, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 4: Bottom rectangle + top two rectangles (horizontal split then vertical)
        for (int hcut = 0; hcut < m - 1; hcut++) {
            for (int vcut = 0; vcut < n - 1; vcut++) {
                int area1 = getMinArea(0, 0, hcut, vcut);
                int area2 = getMinArea(0, vcut + 1, hcut, n - 1);
                int area3 = getMinArea(hcut + 1, 0, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 5: Left rectangle + right two rectangles (vertical split then horizontal)
        for (int vcut = 0; vcut < n - 1; vcut++) {
            for (int hcut = 0; hcut < m - 1; hcut++) {
                int area1 = getMinArea(0, 0, m - 1, vcut);
                int area2 = getMinArea(0, vcut + 1, hcut, n - 1);
                int area3 = getMinArea(hcut + 1, vcut + 1, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        // Pattern 6: Right rectangle + left two rectangles (vertical split then horizontal)
        for (int vcut = 0; vcut < n - 1; vcut++) {
            for (int hcut = 0; hcut < m - 1; hcut++) {
                int area1 = getMinArea(0, 0, hcut, vcut);
                int area2 = getMinArea(hcut + 1, 0, m - 1, vcut);
                int area3 = getMinArea(0, vcut + 1, m - 1, n - 1);
                if (area1 > 0 && area2 > 0 && area3 > 0) {
                    result = min(result, area1 + area2 + area3);
                }
            }
        }
        
        return result;
    }
};