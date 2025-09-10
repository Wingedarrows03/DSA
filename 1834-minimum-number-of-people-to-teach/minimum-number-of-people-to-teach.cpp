#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minimumTeachings(int n, std::vector<std::vector<int>>& languages, std::vector<std::vector<int>>& friendships) {
        int m = languages.size();

        std::vector<std::unordered_set<int>> user_languages(m);
        for (int i = 0; i < m; ++i) {
            user_languages[i] = std::unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        std::unordered_set<int> problem_users;
        for (const auto& f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;

            bool can_communicate = false;
            
            const auto& set_u = user_languages[u];
            const auto& set_v = user_languages[v];
            
            const auto& smaller_set = (set_u.size() < set_v.size()) ? set_u : set_v;
            const auto& larger_set = (set_u.size() < set_v.size()) ? set_v : set_u;

            for (int lang : smaller_set) {
                if (larger_set.count(lang)) {
                    can_communicate = true;
                    break;
                }
            }

            if (!can_communicate) {
                problem_users.insert(u);
                problem_users.insert(v);
            }
        }

        if (problem_users.empty()) {
            return 0;
        }

        std::vector<int> lang_popularity(n + 1, 0);
        for (int user_idx : problem_users) {
            for (int lang : user_languages[user_idx]) {
                lang_popularity[lang]++;
            }
        }

        int max_popularity = 0;
        for (int count : lang_popularity) {
            if (count > max_popularity) {
                max_popularity = count;
            }
        }
        
        return problem_users.size() - max_popularity;
    }
};