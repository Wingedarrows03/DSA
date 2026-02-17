class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(); 
        int m = p.size();
        vector<int> result; //array fot the result 

        if (m > n) return result; //edge case 
        
        //freq map of p 
        vector<int> target(26,0); // target vector (p)
        for (char c : p){
            target[c - 'a']++; //ASCII value ( x - 97 ==)
        }

        //freq map of s 
        vector<int> window(26,0); // window vector (s)

        int right = 0; //scouting pointer 
        int left = 0; //anchor / reducing pointer 

        while(right < n){
            window[s[right]-'a']++; //ASCII value 

            //window slide exceeds m
            if(right - left + 1 > m){
                window[s[left] - 'a']--;
                left ++;
            }

            //window slide meets the m
            if ( right - left + 1 == m){
                if(window == target){
                    result.push_back(left);
                }
                
            }
            right ++;
        }
        return result;
    }
};