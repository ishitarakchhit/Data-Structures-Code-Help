/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

string longestCommonPrefix(vector<string>& strs) {
        string ans= "";
        for(int i=0; i<strs[0].size(); i++){          //loop on the first string
            char ch = strs[0][i];
            for(int j=0; j<strs.size(); j++){         //loop on all the strings
                if(i>= strs[j].size())
                    return ans;
                if(strs[j][i] != ch)
                    return ans;
            }
            ans = ans + strs[0][i];
        }
        return ans;
    }