class Solution {
public:
    // Memoization key: vector of players
    map<vector<int>, pair<int, int>> memo;
    int first, second;

    pair<int, int> dfs(vector<int>& players, int round) {
        if (memo.count(players)) return memo[players];
        int n = players.size();
        int pos1 = find(players.begin(), players.end(), first) - players.begin();
        int pos2 = find(players.begin(), players.end(), second) - players.begin();
        // If they are paired this round
        if (pos1 + pos2 == n - 1) return {round, round};

        vector<vector<int>> pairs;
        int l = 0, r = n - 1;
        while (l < r) {
            int a = players[l], b = players[r];
            if (a == first || a == second) pairs.push_back({a});
            else if (b == first || b == second) pairs.push_back({b});
            else pairs.push_back({a, b});
            ++l; --r;
        }
        if (l == r) pairs.push_back({players[l]});

        int earliest = 100, latest = 0;
        vector<int> curr;
        function<void(int)> backtrack = [&](int idx) {
            if (idx == pairs.size()) {
                vector<int> survivors = curr;
                sort(survivors.begin(), survivors.end());
                auto res = dfs(survivors, round + 1);
                earliest = min(earliest, res.first);
                latest = max(latest, res.second);
                return;
            }
            for (int p : pairs[idx]) {
                curr.push_back(p);
                backtrack(idx + 1);
                curr.pop_back();
            }
        };
        backtrack(0);
        return memo[players] = {earliest, latest};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        first = min(firstPlayer, secondPlayer);
        second = max(firstPlayer, secondPlayer);
        memo.clear();
        vector<int> players(n);
        for (int i = 0; i < n; ++i) players[i] = i + 1;
        auto res = dfs(players, 1);
        return {res.first, res.second};
    }
};