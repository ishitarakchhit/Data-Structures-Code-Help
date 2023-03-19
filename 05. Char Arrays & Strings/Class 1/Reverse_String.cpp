//to reverse a string we follow the same approach as we did in integer arrays. 

class Solution {
public:
    void reverseString(vector<char>& s) {
        int end= s.size()-1;                           //allot the last index to the variable end
        int start= 0;                                  // allot the first index to the variable start
        while(start<end){                              // run a loop till start and end reaches the mid value
            swap(s[start++], s[end--]);                // after swapping the characters increment start by 1 and decrement end by 1
        }
    }
};