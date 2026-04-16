class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.size(); // size of string s
        int n2 = p.size(); // size of string p 

        //result storing vector
        vector<int> result;

        //edge case- 1
        if(n2 > n1) return result;

        // freq map for p (the master list)
        vector <int> target(26,0);
        for(char c : p) //range loop
        {
            target[c - 'a']++; // ASCII char c - 97
        }

        //freq map for s (siliding wndow)
        vector <int> window(26,0);
        int right = 0; // right pointer (scout)
        int left = 0; // left pointer (anchor)

        for(right = 0;  right < n1; right ++){
            window[s[right] - 'a']++; 

            // window size exceeds the p.size
            if (right - left + 1 > n2){
                window[s[left] - 'a']--; // oldest input getting discarded
                left ++;
            }

            // window size meets p.size
            if (right - left + 1 == n2){
                if(window == target){
                    result.push_back(left);
                }
            }

            

        }
        return result;
    }
};