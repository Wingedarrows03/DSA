class Solution {
public:
    bool backspaceCompare(string s, string t) {

        int i = s.size() - 1;
        int j = t.size() - 1;

        int cnti = 0;
        int cntj = 0;

        while(i >= 0 || j >= 0){

            // process s
            while(i >= 0){
                if(s[i] == '#'){
                    cnti++;
                    i--;
                }
                else if(cnti > 0){
                    cnti--;
                    i--;
                }
                else{
                    break;
                }
            }

            // process t
            while(j >= 0){
                if(t[j] == '#'){
                    cntj++;
                    j--;
                }
                else if(cntj > 0){
                    cntj--;
                    j--;
                }
                else{
                    break;
                }
            }

            // compare characters
            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            else if(i >= 0 || j >= 0){
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};