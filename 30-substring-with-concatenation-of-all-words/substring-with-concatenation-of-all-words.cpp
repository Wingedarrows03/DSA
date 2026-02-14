class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        
        if(s.empty() || words.empty()) // edge case 
        {
            return result;
        }

        int wordcount = words.size(); // total number of words in the array
        int wordlen = words[0].length(); // letters in each word 
        int totallen = wordcount * wordlen; // search window
        int n = s.size(); // total size of s 

        unordered_map <string,int> target; // keeps track of the words we have to check with
        for(string &w: words){
            target[w]++;
        }

        //It helps to assess all the possibilities 
        for(int offset = 0; offset < wordlen ; offset++ ) 
        {
            int right = offset; //scout 
            int left = offset; // anchor
            int count = 0; // counter 
            unordered_map<string, int> window; // keep track of current window 

            while(right + wordlen <= n) //moves in chunk 
            {
                string word = s.substr(right, wordlen); //substring extraction of size wordl
                right += wordlen;//expanding the window

                // IF THE WORD IS VALID
                if(target.count(word)) // if we find the word
                {
                    window[word]++; //its added in window list
                    count ++;

                    while(window[word] > target[word]) //if freq exceeds 
                    {
                        string leftword = s.substr(left, wordlen); //substring extraction
                        window[leftword] --;
                        left += wordlen; // keep expanding the left pointer (shrinking)
                        count --;
                    }

                    if( count == wordcount) //if matches all the words
                    {
                        result.push_back(left);
                    }

            
                }
                // WORD IS NOT VALID
                else{
                    window.clear();
                    count = 0;
                    left = right ;

                }

            }
            

        }
        return result;
    }
};