/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

 

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/



    int f(int n, int m, string text1, string text2){
        //we are using shifting of index to reperest base case that has index -1
        vector<int> prev(m+1, -1);
        vector<int> curr(m+1, -1);

        //when n<0 and m>0 they return 0
        for(int j=0; j<=m; j++)
            prev[j] = 0;
        
        //when m<0 and n>0 they return 0
        curr[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else{
                    int left = prev[j];
                    int right = curr[j-1];
                    curr[j] = max(left, right);
                }
            }
            prev = curr;
        }

        return prev[m];
        
    }

    int minInsertions(string s) {
        int n = s.length();
        string s1 = s;
        int m = n;
        reverse(s1.begin(), s1.end());
        return s.size()-f(n, m, s, s1);
    }