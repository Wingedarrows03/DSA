class Solution {
public:
    int compareVersion(string version1, string version2) {
        // Split versions into revision vectors
        vector<int> revisions1 = splitVersion(version1);
        vector<int> revisions2 = splitVersion(version2);
        
        // Get the maximum length to handle different number of revisions
        int maxLen = max(revisions1.size(), revisions2.size());
        
        // Compare each revision position
        for (int i = 0; i < maxLen; i++) {
            // Get revision value, default to 0 if missing
            int rev1 = (i < revisions1.size()) ? revisions1[i] : 0;
            int rev2 = (i < revisions2.size()) ? revisions2[i] : 0;
            
            // Compare current revision values
            if (rev1 < rev2) {
                return -1;
            } else if (rev1 > rev2) {
                return 1;
            }
        }
        
        // All revisions are equal
        return 0;
    }
    
private:
    vector<int> splitVersion(const string& version) {
        vector<int> revisions;
        string current = "";
        
        for (char c : version) {
            if (c == '.') {
                if (!current.empty()) {
                    revisions.push_back(stoi(current));
                    current = "";
                }
            } else {
                current += c;
            }
        }
        
        // Don't forget the last revision
        if (!current.empty()) {
            revisions.push_back(stoi(current));
        }
        
        return revisions;
    }
};
