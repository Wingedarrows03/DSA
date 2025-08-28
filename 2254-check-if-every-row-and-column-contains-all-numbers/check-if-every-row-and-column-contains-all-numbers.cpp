#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

    
        for (int r = 0; r < n; r++) {
            unordered_set<int> rowSet;
            for (int c = 0; c < n; c++) {
                int val = matrix[r][c];
                if (val < 1 || val > n || rowSet.count(val)) {
                    return false; 
                }
                rowSet.insert(val);
            }
        }

       
        for (int c = 0; c < n; c++) {
            unordered_set<int> colSet;
            for (int r = 0; r < n; r++) {
                int val = matrix[r][c];
                if (val < 1 || val > n || colSet.count(val)) {
                    return false; 
                }
                colSet.insert(val);
            }
        }

        return true; 
    }
};
