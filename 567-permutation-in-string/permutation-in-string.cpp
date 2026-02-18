class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        // variable decleration 
        int n = s2.size();
        int m = s1.size();
        vector<int> result;

        //edge case 
        if(m > n){
            return false;
        }

        //freq map for m
        vector<int> target(26,0); // target fre map 
        for(char c : s1){
        target[c - 'a']++; //ASCII 
        }

        //freq map for n
        vector<int> window(26,0); //active window map
        int right = 0; // scouting pointer 
        int left = 0; // anchor / shrinking pointer 
        while ( right < n){
            window[s2[right] - 'a']++;

            //window exceeds the target
            if(right - left + 1 > m){
                window[s2[left] - 'a']--;
                left ++;
            }

            //window meets the target
            if(right - left + 1 == m){
                if(window == target){
                    return true;
                }
            }
            right ++;
        }
        return false;


    }
};