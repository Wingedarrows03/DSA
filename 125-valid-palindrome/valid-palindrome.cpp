class Solution {
public:
bool AlphaNum(char c)
        {
            return(c>='A'&& c<='Z')||
            (c>='a'&& c<='z')||
            (c>='0'&& c<='9');

        }
    bool isPalindrome(string s) {
    
        int n = s.size();
        int l = 0;// left pointer
        int r = n-1; // right pointer 
        while(l<r){
            while (l<r && !AlphaNum(s[l])){
                l++;
            }

            while(l<r && !AlphaNum(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++; r--;

        }
        return true;
    }
};
