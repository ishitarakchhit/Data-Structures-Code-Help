/*
Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        stack<int> s;

        //loop to push all elements into stack according to given sequence
        while(i<pushed.size() && j<popped.size()){

            //loop to check and pop elements when stack's top is equal to popped array's current element 
            while(!s.empty() && s.top()== popped[j]){
                s.pop();
                j++;
            }

            //to push elements into stack when relevant elements have been popped out
            s.push(pushed[i++]);
        }

        //loop to check and pop elements when stack's top is equal to popped array's current element
        while(!s.empty() && j<popped.size() && s.top()== popped[j]){
            s.pop();
            j++;
        }

        if(!s.empty())
            return false;
        return true;
    }