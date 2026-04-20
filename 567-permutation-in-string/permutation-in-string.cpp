class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        //edge case handeling
        if( n1 > n2 ) return false;

        // freq map for s1 (master list)
        vector<int> target(26,0); 
        for(char c: s1){
            target [c - 'a']++; // ASCII Value of 'a' is 97
        }

        //freq map for s2 (window list)
        vector<int> window(26,0);
        int left = 0; //left pointer
        int right = 0; //right pointer 

        for(right = 0; right <= n2-1; right ++){
            window[s2[right] - 'a']++; // right pointer expanding

            //window exceeds the target
            if(right - left + 1 > n1){
                window[s2[left] - 'a']--; //removing the oldest element
                left ++; // left pointer increment 
            }

            // window meets the target
            if(right - left + 1 == n1){
                if (window == target){
                    return true;
                }

            }
            
        }
        return false;
    }
};