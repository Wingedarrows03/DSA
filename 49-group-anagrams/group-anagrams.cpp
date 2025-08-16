class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Step 1: Create a hash map (key = sorted string, value = list of anagrams)
        unordered_map<string, vector<string>> mp;

        // Step 2: For each word, sort it and insert into map
        for (string s : strs) {
            string sortedWord = s;
            sort(sortedWord.begin(), sortedWord.end());  // sorting gives a unique signature
            mp[sortedWord].push_back(s);  // group by sorted word
        }

        // Step 3: Collect results from map
        vector<vector<string>> result;
        for (auto &entry : mp) {
            result.push_back(entry.second);  // take grouped anagrams
        }

        return result;
    }
};