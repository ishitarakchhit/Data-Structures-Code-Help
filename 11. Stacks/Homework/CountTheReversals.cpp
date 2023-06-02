/*
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/

int countRev (string s)
{
    // your code here
    stack<char> st;
    if(s.length()%2!=0){
        return -1;
    }
    //using stack to remove all valid parenthesis
    for(auto ch: s){
        if(st.empty())
            st.push(ch);
        else if(st.top()=='{' && ch == '}')
            st.pop();
        else 
            st.push(ch);
    }
    

    int count =0;
    char ch1, ch2;
    //popping two elements at one time and if they are equal then reverse single time and if not then reverse 2 times to balance
    while(!st.empty()){
        ch1 = st.top(); st.pop();
        ch2 = st.top(); st.pop();
        if(ch1 != ch2){
            count+=2;
        }
        else{
            count+=1;
        }
    }
    return count;
}