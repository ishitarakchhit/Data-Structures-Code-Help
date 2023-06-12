/*
Example 1:

Input:
S = hello
Output: h
Explanation: In the given string, the
first character which is non-repeating
is h, as it appears first and there is
no other 'h' in the string.
Example 2:

Input:
S = zxvczbtxyzvy
Output: c
Explanation: In the given string, 'c' is
the character which is non-repeating. 
Your Task:
You only need to complete the function nonrepeatingCharacter() that takes string S as a parameter and returns the character. If there is no non-repeating character then return '$' .

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |S|

Constraints:
1 <= N <= 103
*/

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       unordered_map<char, int> map;
       queue<char> q;
       
       for(int i=0; i<S.size(); i++){
            map[S[i]]++;
            if(map[S[i]] == 1){
                //cout<<"pushing";
                q.push(S[i]);
            }
            else if(q.empty())
                q.push(-1);
            else{
                //cout<<S[i];
                while(!q.empty() && (q.front()==-1 || map[q.front()] > 1)){
                    //cout<<"popping";
                    q.pop();
                    if(q.empty()){
                        break;
                    }
                }
            }
       }
      
       if(q.empty()){
           
           q.push('-1');
       }
        return q.front();
    }

};