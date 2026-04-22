class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        //edge case handelling
        if(n2 > n1) return "";

        //freq map of t (master list)
        vector<int> target(128,0); // ASCII value for small and capital letters is 128
        int uniquechar = 0; // counts unique letters
        for (char c : t){
            if (target[c] == 0) // if the letter hits 0 times
            {
                uniquechar ++; // increase the counter
            }
            target[c]++; // move the pointer 
        }

        // freq map for s (Window - list )
        vector<int> window(128,0); 
        int left = 0; // left pointer
        int right = 0; // right pointer 
        int satisfied = 0; // required section of the substring
        int minlen = INT_MAX; // counts minimum length 
        int startnode = 0; // starting of the best window 

        for(right = 0; right < n1; right++){
            char c = s[right]; // Get current character
            window[c]++; // expansion of the window
            
            //check if the expansion meets the requirement 
            if(target[c] > 0 && window[c] == target[c] ){
                satisfied ++; // increase the counter
            }

            // Contraction phase 
            while( satisfied == uniquechar){

                //Update the minimum substring found till now
                if(right - left + 1 < minlen){
                    minlen = right - left + 1;
                    startnode = left; // fixing start node at left 
                }

                // Shrink the window from the left
                char charleft = s[left]; // lowercase 'left' to match definition
                window[charleft] --; // shrinking the window

                // If shrinking the window makes the window invalid than reduce satisfied
                if(target[charleft] > 0 && window[charleft] < target[charleft]){
                    satisfied --;
                }

                left++; // increment left pointer
            }
        } 

        // Final return 
        if(minlen == INT_MAX){
            return "";
        }  

        return s.substr(startnode, minlen); // Fixed 'subtr' to 'substr'
    }
};