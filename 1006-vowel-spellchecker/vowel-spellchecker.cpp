class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        std::unordered_set<string> exact_words(wordlist.begin(), wordlist.end());
        std::unordered_map<string, string> case_insensitive_map;
        std::unordered_map<string, string> vowel_error_map;

        for (const string& word : wordlist) {
            string lower_word = to_lower(word);
            
            if (case_insensitive_map.find(lower_word) == case_insensitive_map.end()) {
                case_insensitive_map[lower_word] = word;
            }
            
            string devoweled_word = devowel(lower_word);
            if (vowel_error_map.find(devoweled_word) == vowel_error_map.end()) {
                vowel_error_map[devoweled_word] = word;
            }
        }

        std::vector<string> result;
        for (const string& query : queries) {
            if (exact_words.count(query)) {
                result.push_back(query);
                continue;
            }

            string lower_query = to_lower(query);
            if (case_insensitive_map.count(lower_query)) {
                result.push_back(case_insensitive_map[lower_query]);
                continue;
            }

            string devoweled_query = devowel(lower_query);
            if (vowel_error_map.count(devoweled_query)) {
                result.push_back(vowel_error_map[devoweled_query]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }

private:
    string to_lower(const string& s) {
        string lower_s = s;
        std::transform(lower_s.begin(), lower_s.end(), lower_s.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        return lower_s;
    }
    
    bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string devowel(const string& s) {
        string devoweled_s = s;
        for (char& c : devoweled_s) {
            if (is_vowel(c)) {
                c = '#';
            }
        }
        return devoweled_s;
    }
};