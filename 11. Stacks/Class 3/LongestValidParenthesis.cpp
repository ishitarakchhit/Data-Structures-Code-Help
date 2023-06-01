/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
*/


class Solution {
public:
    //Approach: using stack, push index which has opening bracket and whenever you encounter a closing bracket then pop the top most element Thwn calculate the length by i-top(), since now top contains the index just before the opeing bracket starts, this helps us to calculate the length of the longest valid parenthesis
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i- st.top();
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};