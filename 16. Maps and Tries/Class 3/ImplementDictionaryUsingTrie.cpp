#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
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
        root = root->children[index];
    }
    insertWord(root, word.substr(1));

}



//function to get all words after the current character
void getWord(TrieNode* root, vector<string> &line, string& word){
    if(root->isTerminal){             //when the current character is the last character of the word then push it into the ans string
        line.push_back(word);         //---!mistake: added return satemnet in base case which prevented all words to be stored
    }  

    for(int i=0; i<26; i++){
        if(root->children[i]){
            
            word.push_back(root->children[i]->data);
            getWord(root->children[i], line, word);
            word.pop_back();
        }
    }

}


//function to implement dictionary using trie
vector<vector<string>> getSuggestions(TrieNode* root, string input){
    vector<vector<string>> ans;
    string word = "";
    for(int i=0; i<input.length(); i++){
        char ch = input[i];
        int index = ch - 'a';
        word.push_back(ch);

        vector<string> line;
        root = root->children[index];
        string wordcopy = word;
        getWord(root, line, wordcopy);
        ans.push_back(line);

    }
    return ans;

}


int main(){
    TrieNode* root = new TrieNode('-');

    //inserting various words in trie
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "lover");
    insertWord(root, "lane");
    insertWord(root, "lost");
    insertWord(root, "lend");
    insertWord(root, "loving");
    insertWord(root, "love");
    insertWord(root, "lord");
    insertWord(root, "least");
    insertWord(root, "last");
    insertWord(root, "list");
    insertWord(root, "live");
    cout<<"inserted"<<endl;

    string inpu = "lost";
    vector<vector<string>> ans = getSuggestions(root, inpu);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j <ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

    return 0;
}