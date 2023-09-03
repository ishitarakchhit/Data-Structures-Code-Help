/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
*/


//---------------Solution keep lcs entact then insert or remove the other characters 

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

    

    int minDistance(string word1, string word2) {
        int lcs = f(word1.length(), word2.length(), word1, word2);

        return word1.length()-lcs + word2.length()-lcs;
    }