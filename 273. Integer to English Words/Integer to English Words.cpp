#include <vector>
#include <string>

class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";
        
        std::vector<std::string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        std::vector<std::string> below_100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        std::vector<std::string> above_100 = {"Hundred", "Thousand", "Million", "Billion"};
        
        return helper(num, below_20, below_100, above_100).substr(1);
    }
    
private:
    std::string helper(int num, std::vector<std::string>& below_20, std::vector<std::string>& below_100, std::vector<std::string>& above_100) {
        if (num >= 1000000000) return helper(num / 1000000000, below_20, below_100, above_100) + " " + above_100[3] + helper(num % 1000000000, below_20, below_100, above_100);
        else if (num >= 1000000) return helper(num / 1000000, below_20, below_100, above_100) + " " + above_100[2] + helper(num % 1000000, below_20, below_100, above_100);
        else if (num >= 1000) return helper(num / 1000, below_20, below_100, above_100) + " " + above_100[1] + helper(num % 1000, below_20, below_100, above_100);
        else if (num >= 100) return helper(num / 100, below_20, below_100, above_100) + " " + above_100[0] + helper(num % 100, below_20, below_100, above_100);
        else if (num >= 20) return " " + below_100[num / 10] + helper(num % 10, below_20, below_100, above_100);
        else if (num >= 1) return " " + below_20[num];
        else return "";
    }
};