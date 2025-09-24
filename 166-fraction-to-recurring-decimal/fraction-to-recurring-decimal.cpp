class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        std::string result = "";

        if ((numerator > 0) ^ (denominator > 0)) {
            result += "-";
        }

        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));

        result += std::to_string(num / den);
        long long remainder = num % den;

        if (remainder == 0) {
            return result;
        }

        result += ".";

        std::unordered_map<long long, int> remainderMap;

        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                result.insert(remainderMap[remainder], "(");
                result += ")";
                break;
            }

            remainderMap[remainder] = result.length();
            
            remainder *= 10;
            
            result += std::to_string(remainder / den);
            
            remainder %= den;
        }

        return result;
    }
};