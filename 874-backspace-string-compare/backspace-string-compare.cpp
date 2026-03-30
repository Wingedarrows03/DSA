class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1; // pointer for s 
        int j = t.size() - 1; // pointer for t

        //counter
        int cnti = 0; // counter for i
        int cntj = 0; //counter for j

        while(i >= 0 || j >= 0){
            // processing s 
            while(i >= 0){
                // i encounters #
                if (s[i] == '#'){
                    cnti ++; // counter will increase 
                    i --; // i will skip it 
                }
                // if i ecounters valid char 
                else if (cnti > 0){
                    cnti --; //reduced the counter
                    i--; // skipping the next char after #
                }
                else{
                    break;
                }

            }

            //processing t
            while(j >= 0){
                // j encounters #
                if(t[j] == '#'){
                    cntj ++; //counter j will increase 
                    j --; //j will skip #
                }
                else if(cntj > 0){
                    // j encounter valid char 
                    cntj --; // counter value will decrease 
                    j --; // skip the next valid char after #
                }
                else{
                    break;
                }

            }
            // comparing the strings 
            if( i>=0 && j>=0){
                if(s[i] != t[j]){
                    // the letter is not matching
                    return false;
                }

            }

            // if any one of the string is still left with char
           else  if( i>=0 || j>=0){
            return false;
            }

            // if pointers bypass the checks
            i --;
            j --;

        }
        return true;

        
    }
};