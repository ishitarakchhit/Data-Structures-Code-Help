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

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
        childCount = 0;
    }

};


//function to insert a word in trie
void insertWord(TrieNode* root, string word){
    //BC: if the word has exhausted mark root as terminal
    if(word.length() == 0){
        root->isTerminal = true;             
        return;
    }

    char ch = word[0];
    int index = ch-'a';

    //if current character already exists then go to the current character trie node to insert further characters of word 
    if(root->children[index] != NULL){
       root = root->children[index];
    }

    // otherwise create a new trienode to store the value of current character
    else{
        TrieNode* temp = new TrieNode(ch);
        root->children[index] = temp;
        root->childCount++;            //---- ! mistake: added this line below the next line
        root = root->children[index];
    }
    insertWord(root, word.substr(1));

}

class Solution {
public:
    
    string findLCP(TrieNode* root, string first){
        string ans = "";

        if(root->isTerminal )                     //-----! mistake: did not handle empty string
            return ans;

        for(int i =0; i< first.length(); i++){         // ----! did not run loop in the first word instead ran in the whole array
            char ch = first[i];
            int index = ch - 'a';
            if(root->childCount == 1){
                ans.push_back(ch);
                root = root->children[index];
            }
            else
                break;
            if(root->isTerminal == true)
                break;

        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('\0');

        //pushing all strings into trie
        for(int i=0; i<strs.size(); i++){
            insertWord(root, strs[i]);
        }
        string first = strs[0];      
        return findLCP(root, first);
    }
};