class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        bool toDelete = false;
    };
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Build the trie
        TrieNode* root = new TrieNode();
        for (auto& path : paths) {
            TrieNode* curr = root;
            for (string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new TrieNode();
                }
                curr = curr->children[folder];
            }
        }
        
        // Map to store signature -> list of nodes with that signature
        unordered_map<string, vector<TrieNode*>> signatureMap;
        
        // Compute signatures and find duplicates
        computeSignature(root, signatureMap);
        
        // Mark nodes for deletion if they have duplicates and non-empty signature
        for (auto& pair : signatureMap) {
            if (pair.second.size() > 1 && !pair.first.empty()) {
                for (TrieNode* node : pair.second) {
                    markForDeletion(node);
                }
            }
        }
        
        // Collect remaining paths
        vector<vector<string>> result;
        vector<string> currentPath;
        collectPaths(root, currentPath, result);
        
        return result;
    }
    
private:
    string computeSignature(TrieNode* node, unordered_map<string, vector<TrieNode*>>& signatureMap) {
        if (!node) return "";
        
        // Get signatures of all children and sort them
        vector<pair<string, string>> childSignatures; // (folder_name, signature)
        for (auto& pair : node->children) {
            string childSig = computeSignature(pair.second, signatureMap);
            childSignatures.push_back({pair.first, childSig});
        }
        
        // Sort by folder name to ensure consistent signature
        sort(childSignatures.begin(), childSignatures.end());
        
        // Build signature for current node
        string signature = "";
        for (auto& pair : childSignatures) {
            signature += "(" + pair.first + pair.second + ")";
        }
        
        // Add this node to the signature map
        signatureMap[signature].push_back(node);
        
        return signature;
    }
    
    void markForDeletion(TrieNode* node) {
        if (!node) return;
        node->toDelete = true;
        for (auto& pair : node->children) {
            markForDeletion(pair.second);
        }
    }
    
    void collectPaths(TrieNode* node, vector<string>& currentPath, vector<vector<string>>& result) {
        if (!node) return;
        
        for (auto& pair : node->children) {
            if (!pair.second->toDelete) {
                currentPath.push_back(pair.first);
                result.push_back(currentPath);
                collectPaths(pair.second, currentPath, result);
                currentPath.pop_back();
            }
        }
    }
};