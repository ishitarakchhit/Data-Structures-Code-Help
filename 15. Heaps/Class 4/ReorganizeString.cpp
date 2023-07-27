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



class Solution {
public:

    class node{
        public:
        char alphabet;
        int freq;
        node(char a, int f){
            this->alphabet = a;
            this->freq = f;
        }
    };

    class compare{
        public:
        bool operator()(node a, node b){
            return a.freq < b.freq;
        }
    };

    string reorganizeString(string s) {
        unordered_map<char, int> map;
        string ans;

        //mapping all the alphabets by their frequency
        for(int i=0; i<s.size(); i++){
            map[s[i]]++;
        }

        //creating max heap
        priority_queue<node, vector<node>, compare> maxheap;
        for(auto i = map.begin(); i!=map.end(); i++){
            maxheap.push(node(i->first, i->second));
        }

        //popping two elemnts from heap at one time then pusing it in ans string. Further reduing the frequency and pushing the alphabet when its frequency is more than 0
        while(maxheap.size()>1){
            node a = maxheap.top();
            maxheap.pop();
            node b = maxheap.top();
            maxheap.pop();
            ans = ans+ a.alphabet;
            ans = ans+ b.alphabet;

            map[a.alphabet]--;
            map[b.alphabet]--;
            if(map[a.alphabet]>0){
                node newnode = node(a.alphabet, map[a.alphabet]);
                maxheap.push(newnode);
            }
            if(map[b.alphabet]>0){
                node newnode = node(b.alphabet, map[b.alphabet]);
                maxheap.push(newnode);
            }
        }

        //for the last left element in heap
        if(!maxheap.empty()){
            node top = maxheap.top();
            if(top.freq >1)
                return "";
            ans = ans+ top.alphabet;
        }
        return ans;


    }
};