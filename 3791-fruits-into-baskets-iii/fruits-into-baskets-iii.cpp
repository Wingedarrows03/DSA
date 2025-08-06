class Solution {
private:
    // Segment tree for range maximum query and point update
    vector<int> tree;
    int size;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2*node, start, mid, idx, val);
            } else {
                update(2*node+1, mid+1, end, idx, val);
            }
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }
    
    int queryLeftmost(int node, int start, int end, int minVal) {
        if (start == end) {
            return (tree[node] >= minVal) ? start : -1;
        }
        
        int mid = (start + end) / 2;
        // Check left subtree first (leftmost priority)
        if (tree[2*node] >= minVal) {
            return queryLeftmost(2*node, start, mid, minVal);
        }
        // Then check right subtree
        if (tree[2*node+1] >= minVal) {
            return queryLeftmost(2*node+1, mid+1, end, minVal);
        }
        return -1;
    }
    
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        size = n;
        tree.resize(4 * n);
        
        // Build segment tree with basket capacities
        build(baskets, 1, 0, n-1);
        
        int unplaced = 0;
        
        for (int i = 0; i < n; i++) {
            int fruitQuantity = fruits[i];
            
            // Find leftmost available basket with sufficient capacity
            int basketIdx = queryLeftmost(1, 0, n-1, fruitQuantity);
            
            if (basketIdx != -1) {
                // Mark basket as used by setting capacity to 0
                update(1, 0, n-1, basketIdx, 0);
            } else {
                unplaced++;
            }
        }
        
        return unplaced;
    }
};