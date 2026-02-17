class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(); 
        int m = p.size();
        vector<int> result; //push my result here 

        if(m > n) return result; // edge case handelling 

        //freq map of m 
        vector<int> target(26,0); // target freq map
        for(char c : p){
            target[c - 'a']++; //ASCII 
        }

        //freq map of n 
        vector<int> window(26,0); // active window freq map 
        int right = 0; //scouting pointer 
        int left = 0; //anchor pointer / reducing pointer 

        while(right < n){
            window[s[right] - 'a']++;

            // window size exceeds m
            if( right - left + 1 > m){
                window[s[left] - 'a']--; 
                left ++;
            }

            //window size meets the m
            if( right - left + 1 == m){
                if(window == target ){
                    result.push_back(left);
                }
            }
            right ++;
        }
        return result;

    }
};