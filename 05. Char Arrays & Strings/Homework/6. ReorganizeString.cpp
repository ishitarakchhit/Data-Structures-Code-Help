/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/


string reorganizeString(string s) {
        vector<int> mp(26, 0);
        string ans="";

        //creating a temporary string to further store our answer
        for(int i=0; i<s.length(); i++){
            ans.push_back('$');
        }

        //return ans;
        //mapping the frequency of all characters
        for(auto it:s)
            mp[it-'a']++;
        

        char ch;
        int freq = INT_MIN;
        //to find the max frequency element
        for(int j=0; j<26; j++){
            if(mp[j]>freq){
                freq = mp[j];
                ch = j + 'a';
                //cout<<j<<" "<<mp[j];
            }
        }

        int i=0;

        //placing most frequent characters alternatively and 
        //if not exhausted then it is not possbile to create a reorganized string 
        while(freq>0 && i<s.length()){
            ans[i] = ch;
            freq--;
            i+=2;
        }

        if(freq>0) return "";

        mp[ch-'a'] = 0;

        for(int k=0; k<26; k++){
            while(mp[k]>0){
                i = i>=s.length()?1:i;
                ans[i] = k + 'a';
                mp[k]--;
                i+=2;
            }
        }

        return ans;
    }