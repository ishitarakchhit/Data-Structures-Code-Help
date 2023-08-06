/*
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/

class Solution {
public:
vector<pair<int, string>> map = {{1000000000, "Billion", }, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        for(auto it: map){
            string a = "";
            string b = "";
            string c = "";

            if(num >= it.first){
                b = it.second;

                if(num >= 100){
                    a = numberToWords(num/it.first) + " ";
                }
                if(num% it.first != 0){
                    c = " " + numberToWords(num%it.first);
                }

                return a + b + c;
            }
        }
        return "";
    }
};