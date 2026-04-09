class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result; // result will be stored here 

        //edge case - 1
        if(s.size() == 0 || words.size() == 0){
            return result;
        }

        //general decleration
        int n = s.size(); // size of string
        int wordsize = words.size(); // size of words (L)
        int wordlength = words[0].size(); // length of each word 
        int k = wordsize * wordlength; // window of the problem

        //Map decleration - 1 ( area of operation - words)
        unordered_map<string, int> target;
        for(int i = 0; i < wordsize; i++){
            string w = words[i];
            target[w]++; // building the target frequency map
        }

        //pointer decleration (area of operation - s)
        for (int pointer = 0; pointer < wordlength; pointer ++){
            int left = pointer; //left pointer 
            int right = pointer; //right pointer 
            int cnt = 0; //counter for valid words found

            //Map decleration - 2 (area of operation - s)
            unordered_map<string, int> seen;

            // movement in chunks 
            while(right + wordlength <= n){
                string word = s.substr(right, wordlength); // cutting each chunk
                right += wordlength; // expansion of right pointer in chunk

                // if word hits the target 
                if(target.count(word)){
                    seen[word]++; // adding found word to current window map
                    cnt++; // incrementing the valid word count

                    // frequency allowed exceeds
                    while (seen[word] > target[word]){
                        string leftword = s.substr(left, wordlength); // identifying the oldest word
                        seen[leftword]--; // removing it from current map
                        cnt--; // decrementing the valid word count
                        left += wordlength; // shrinking from the left in chunks
                    }

                    // window matches target size
                    if(cnt == wordsize){
                        result.push_back(left); // recording the starting index
                    }
                }
                else {
                    // reset case: hit a word not in target
                    seen.clear(); // clearing the current window map
                    cnt = 0; // resetting the valid word count
                    left = right; // jumping left pointer to the new start
                }
            }
        }
        
        return result; // returning the final list of indices
    }
};