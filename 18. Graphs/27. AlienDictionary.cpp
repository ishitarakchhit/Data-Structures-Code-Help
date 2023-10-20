/*
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N * |S| + K) , where |S| denotes maximum length.
Expected Space Compelxity: O(K)


Constraints:
1 ≤ N, M ≤ 300
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 50
*/


//Approach: take two strings and compare characters sequentially and simultaneously create a DG
    //finally fetch the sequence of characters in linear ordering using topo sort and also include the characters which were not a part of any word
    
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> graph(K);
        
        //to create a directed graph using ordering of characters in given strings
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            //compare characters of both strings
            int size = min(s1.size(), s2.size());
            for(int j=0; j<size; j++){
                if(s1[j] != s2[j]){
                    int node = s1[j]-'a';
                    graph[node].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        
        
        //to find linear ordering using topo sort
        //to store indegrees of all characters
        vector<int> indegree(K, 0);
        
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                int node = graph[i][j];
                indegree[node]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<K; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        string ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node + 'a');
            
            for(int i=0; i<graph[node].size(); i++){
                if(--indegree[graph[node][i]] == 0)
                    q.push(graph[node][i]);
            }
        }
        
        
        //cout<<ans<<endl;
        return ans;
    }