class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Root the tree at node 0
        vector<int> subtreeXor(n);
        vector<int> startTime(n), endTime(n);
        int timer = 0;
        
        // DFS to compute subtree XOR and DFS timestamps
        function<void(int, int)> dfs = [&](int node, int parent) {
            startTime[node] = timer++;
            subtreeXor[node] = nums[node];
            
            for (int child : adj[node]) {
                if (child != parent) {
                    dfs(child, node);
                    subtreeXor[node] ^= subtreeXor[child];
                }
            }
            
            endTime[node] = timer++;
        };
        
        dfs(0, -1);
        int totalXor = subtreeXor[0];
        
        int minScore = INT_MAX;
        
        // Try all pairs of nodes (representing edges to their parents)
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (i == j) continue;
                
                int xor1, xor2, xor3;
                
                // Check ancestor relationship using DFS timestamps
                bool iAncestorOfJ = (startTime[i] < startTime[j] && endTime[j] < endTime[i]);
                bool jAncestorOfI = (startTime[j] < startTime[i] && endTime[i] < endTime[j]);
                
                if (iAncestorOfJ) {
                    // i is ancestor of j
                    xor1 = subtreeXor[j];
                    xor2 = subtreeXor[i] ^ subtreeXor[j];
                    xor3 = totalXor ^ subtreeXor[i];
                } else if (jAncestorOfI) {
                    // j is ancestor of i
                    xor1 = subtreeXor[i];
                    xor2 = subtreeXor[j] ^ subtreeXor[i];
                    xor3 = totalXor ^ subtreeXor[j];
                } else {
                    // i and j are in different subtrees
                    xor1 = subtreeXor[i];
                    xor2 = subtreeXor[j];
                    xor3 = totalXor ^ subtreeXor[i] ^ subtreeXor[j];
                }
                
                int minXor = min({xor1, xor2, xor3});
                int maxXor = max({xor1, xor2, xor3});
                minScore = min(minScore, maxXor - minXor);
            }
        }
        
        return minScore;
    }
};