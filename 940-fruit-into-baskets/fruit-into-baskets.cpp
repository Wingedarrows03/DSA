#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int windowStart = 0;
        int maxFruits = 0;
        std::unordered_map<int, int> fruitCount;

        for (int windowEnd = 0; windowEnd < fruits.size(); ++windowEnd) {
            int rightFruit = fruits[windowEnd];
            fruitCount[rightFruit]++;

            while (fruitCount.size() > 2) {
                int leftFruit = fruits[windowStart];
                fruitCount[leftFruit]--;
                if (fruitCount[leftFruit] == 0) {
                    fruitCount.erase(leftFruit);
                }
                windowStart++;
            }

            maxFruits = std::max(maxFruits, windowEnd - windowStart + 1);
        }

        return maxFruits;
    }
};