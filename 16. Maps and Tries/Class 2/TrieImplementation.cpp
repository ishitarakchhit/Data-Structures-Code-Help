#include<iostream>
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

// function to search for a word in trie
bool search(TrieNode* root, string word){
    if(word.length() == 0)
        return root->isTerminal;
    
    char ch = word[0];
    int index = ch-'a';

    //match a character with the help of its index, if it is present check further other return false
    if(root->children[index] != NULL){
        root = root->children[index];
    }
    else{
        return false;
    }

    return search(root, word.substr(1));
}


//function to delete a word from trie
void deletenode(TrieNode* root, string word){
    if(word.length() == 0){
        if(root->isTerminal == false)
            cout<<endl<<"word is not present";
        root->isTerminal = false;
        return;
    }
    char ch = word[0];
    int index = ch-'a';
    
    //to go the next children via character of word
    if(root->children[index]!=NULL)
        root = root->children[index];
    else{
        cout<<endl<<"word is not present";
        return;
    }
    
    deletenode(root, word.substr(1));  
}

int main(){
    TrieNode* root = new TrieNode('-');

    //inserting various words in trie
    insertWord(root, "love");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "leetcode");
    insertWord(root, "calling");
    insertWord(root, "laxmi");
    insertWord(root, "calling");
    insertWord(root, "babbar");
    insertWord(root, "india");
    insertWord(root, "supreme");
    cout<<"inserted"<<endl;

    search(root, "love")==1? cout<<"Present": cout<<"Not present";
    cout<<endl;
    search(root, "code")==1? cout<<"Present": cout<<"Not present";

    deletenode(root, "code");
    cout<<endl;
    search(root, "code")==1? cout<<"Present": cout<<"Not present";
    deletenode(root, "code");
    deletenode(root, "copy");
    return 0;
}