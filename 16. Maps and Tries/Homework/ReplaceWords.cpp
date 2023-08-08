/*
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/


class Solution {
public:
    class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    trieNode(char ch){
        this->data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


//function to insert words in trie
void insertWord(trieNode* root, string word){
    if( word.length()==0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch-'a';

    //now check if the current character already exists or not in the trienode
    if( root->children[index] == NULL){
        trieNode* child = new trieNode(ch);
        root->children[index] = child;
    }
    root = root->children[index];
    insertWord(root, word.substr(1));
}


//function to match a word from trie and push it to ans string
int wordMatch(trieNode* root, string &word){

    for(int i=0; i<word.size(); i++){
        
        char ch = word[i];
        int index = ch-'a';
         
         //if word is not found in trie then return -1 so that other function can push the original word
        if(root->children[index] == NULL){
            return -1;
        }

        else{
            root= root->children[index];                //----! mistake: added this line in the end so it was not able to check for correct root's terminal
            if(root->isTerminal == true){
                return i;
            }
        }
    }
    return -1;
}

    string replaceWords(vector<string>& dictionary, string sentence) {
        trieNode* root = new trieNode('-');
        string ans = "";

        //inserting all the words in trie
        for(int i=0; i<dictionary.size(); i++){
            insertWord(root, dictionary[i]);
        }

        string temp= "";

        //now start comparing words from sentence with trie words
        for(int i=0; i<sentence.size(); i++){

            //to include the current ch if it is the last one
            if(i == sentence.size()-1)
                temp = temp + sentence[i];

            //to fetch word from sentence
            if(sentence[i] == ' ' || i== sentence.size()-1){

                //now match the current word with trie dictionary
                int index = wordMatch(root, temp); 
                if(index == -1)
                    ans = ans + temp + " ";
                else{
                    ans = ans + temp.substr(0, index+1) + " ";
                }
                temp = "";
            }
            else{
                temp += sentence[i];
            }


        }

        //to pop the trailing space
        ans.pop_back();

        return ans;
    }
};