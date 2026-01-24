class Solution {
public:
    bool alphanum(char c){
        return
        (c >= 'A' && c<='Z')||
        (c >= 'a' && c<= 'z') ||
        (c >= '0' && c<= '9');
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;

        while(l<r){
            while(l<r && !alphanum(s[l])){
                l++;
            }
            while(l<r && !alphanum(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};