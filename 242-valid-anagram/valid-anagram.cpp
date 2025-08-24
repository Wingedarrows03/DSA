class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
       

        if(s1 != t1){
            return false;
        }
        unordered_map<char,int> mpp1;
        unordered_map<char,int> mpp2;
        
        for(int i = 0;i<=s1;i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        if (mpp1 == mpp2) return true;
        return 0;


    }
};
