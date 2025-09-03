class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int ax = points[i][0], ay = points[i][1];
            
            // Get all points that could be Bob (right and down from Alice)
            vector<pair<int, int>> candidates;
            for (int j = 0; j < n; j++) {
                if (i != j && points[j][0] >= ax && points[j][1] <= ay) {
                    candidates.push_back({points[j][0], points[j][1]});
                }
            }
            
            // Sort by x, then by -y (so higher y comes first for same x)
            sort(candidates.begin(), candidates.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second > b.second;
            });
            
            // Use sweep line: for each x-coordinate, find the highest y that's not blocked
            int maxY = INT_MIN;
            for (auto& p : candidates) {
                int x = p.first, y = p.second;
                if (y > maxY) {
                    count++;
                    maxY = y;
                }
            }
        }
        
        return count;
    }
};