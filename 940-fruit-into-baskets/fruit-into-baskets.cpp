class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0; // left pointer 
        int right = 0; //right pointer 
        int maxfruits = 0; // maximum 

        unordered_map<int,int> freq; // map to keep track of fequency and type of trees

        for(right = 0; right <= n-1; right++){
            freq[fruits[right]]++; // window is expanding

            // when map size > 2
            while(freq.size() > 2){
                freq[fruits[left]]--; // removing the oldest element first
                if (freq[fruits[left]] == 0){
                    freq.erase(fruits[left]); // removing empty fruit types
                }
                left ++; // left pointer moving

            }
            maxfruits = max(maxfruits,right-left+1);

        }
        return maxfruits;

    }
};