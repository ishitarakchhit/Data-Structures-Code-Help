/*
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

//creating a class ndoe
class node{
    public:
    char letter;
    int data;
    node(char letter, int data){
        this->letter = letter;
        this->data = data;
    }
};

//creating class heap for customised datatype
class compare{
    public:
    bool operator()(node a, node b){
        return a.data < b.data;
    }
};

class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        priority_queue<node,vector<node>, compare> maxheap;

        //pushing nodes in heap
        if(a>0)
        maxheap.push(node('a', a));
        if(b>0)
        maxheap.push(node('b', b));        
        if(c>0)
        maxheap.push(node('c', c));

        string ans = "";

        //popping two elements at one time so as to push bbaabb instead of bbbbaa. Further 2nd element is only pushed two times when it has frequency higher than first one so as to create string bbabbab (longer string) instead of bbaabb
        while(maxheap.size() >1){
            node top1 = maxheap.top();
            maxheap.pop();
            node top2 = maxheap.top();
            maxheap.pop();

            if(top1.data >1){
                ans = ans + top1.letter;
                ans = ans + top1.letter;
                top1.data-=2;
            }
            else {
                ans = ans + top1.letter;
                top1.data--;
            }
            if(top2.data >1 && top2.data > top1.data){
                ans = ans + top2.letter;
                ans = ans + top2.letter;
                top2.data-=2;
            }
            else {
                ans = ans + top2.letter;
                top2.data--;
            }

            if(top1.data >0){
                maxheap.push(node(top1.letter, top1.data));
            }
            if(top2.data > 0){
                maxheap.push(node(top2.letter, top2.data));
            }
        }

        //to push the remaining one element from heap to ans string
        if(maxheap.size()>0){
            ans = ans + maxheap.top().letter;
            if(maxheap.top().data > 1)
                ans = ans + maxheap.top().letter;
        }
        
        return ans;
    }
};