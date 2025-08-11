class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        long long mod = 1e9 + 7;

        // 1. Generate the 'powers' array by checking the bits of n.
        // We iterate up to 30 because 2^30 > 10^9.
        for (int i = 0; i < 31; ++i) {
            // Check if the i-th bit is set
            if ((n >> i) & 1) {
                // If the bit is set, 2^i is part of the sum.
                powers.push_back(1LL << i); 
            }
        }

        vector<int> answers;
        // 2. Process each query.
        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];

            long long product = 1;
            // 3. Calculate the product for the given range [left, right].
            // Apply modulo at each multiplication to prevent overflow.
            for (int i = left; i <= right; ++i) {
                product = (product * powers[i]) % mod;
            }
            answers.push_back(product);
        }

        return answers;
    }
};