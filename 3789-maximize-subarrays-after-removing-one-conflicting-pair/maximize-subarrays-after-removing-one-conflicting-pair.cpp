class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
int m = conflictingPairs.size();
        vector<vector<pair<int,int>>> edges(n+2);
        for (int i = 0; i < m; i++) {
            int a = conflictingPairs[i][0];
            int b = conflictingPairs[i][1];
            if (a > b) swap(a, b);
            edges[a].push_back({b, i});
        }
        
        multiset<pair<int,int>> ms;
        vector<int> first_b(n+2), first_id(n+2), second_b(n+2);
        for (int l = n; l >= 1; l--) {
            for (auto &p : edges[l]) {
                ms.insert(p);
            }
            if (!ms.empty()) {
                auto it = ms.begin();
                first_b[l] = it->first;
                first_id[l] = it->second;
                auto it2 = next(it);
                second_b[l] = (it2 != ms.end() ? it2->first : n+1);
            } else {
                first_b[l] = n+1;
                first_id[l] = -1;
                second_b[l] = n+1;
            }
        }
        
        long long sum1 = 0;
        vector<long long> sum1k(m), sum2k(m);
        for (int l = 1; l <= n; l++) {
            long long d1 = (long long)first_b[l] - l;
            long long d2 = (long long)second_b[l] - l;
            sum1 += d1;
            int id = first_id[l];
            if (id >= 0) {
                sum1k[id] += d1;
                sum2k[id] += d2;
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            long long now = sum1 - sum1k[i] + sum2k[i];
            if (now > ans) ans = now;
        }
        return ans;
    }
};