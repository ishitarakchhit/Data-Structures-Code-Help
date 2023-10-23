/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
The sum of all shortest transformation sequences does not exceed 105.
*/

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
         //inserting all words into set
        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        //creating a queue to perform all operations
        queue<vector<string>> q;
        q.push({beginWord});
        
        int level = 0;
        
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
        
                        
            if(vec.size() > level){ //cout<<"here";
                level++;
                for(auto it: usedOnLevel)
                    st.erase(it);
                usedOnLevel.clear();
            }
            
            string word = vec.back();
            
            if(word == endWord){
                if(ans.size() == 0)
                    ans.push_back(vec);
                else{
                    if(ans[0].size() == vec.size())
                        ans.push_back(vec);
                }
            }

            for(int i=0; i<word.size();i++){
                char original = word[i];
                
                for(char ch ='a'; ch<='z'; ch++){
                    word[i] = ch;
                    
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                        
                    }
                }
                word[i] = original;
            }
            
            
        }
        
        return ans;
    }