/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

class Solution {
public:

    string decodeString(string s) {
        stack<string> st;
        string num;
        int i =0;
        string temp = "";

        //loop to traverse through the string s
        while(i< s.length()){
            
            if(s[i] == ']'){
                //to retrive the string inside []
                while(st.top()  != "["){
                    temp = temp + st.top();
                    st.pop();
                }
                st.pop();
                //to retrive the number occuring just before [] which represents the number of repition for substring
                while(!st.empty() && st.top()[0]<='9' && st.top()[0]>='0'){
                    num = num+ st.top();
                    st.pop();
                }
                //to reverse to get the original no. in string
                reverse(num.begin(), num.end());

                //to convert the string to int
                int repeat = stoi(num); 
                num="";
                string ans="";

                //to push the substring repeat no. of times
                while(repeat>0){
                    ans = ans+ temp;
                    repeat--;
                }

                //to push the encoded substring into stack
                st.push(ans);
                temp = "";
            }
            
            //to push the elements into stack when it is not ']'
            else{
                //to convert character into string
                string ran(1, s[i]);
                st.push(ran);
            }
            i++;
        }

        //to pop all string from stack to answer string
        s ="";
        while(!st.empty()){
            s = s+ st.top();
            st.pop();
        }

        //to reverse the string into final correct answer
        reverse(s.begin(), s.end());

        //to return the string
        return s;
    }
};