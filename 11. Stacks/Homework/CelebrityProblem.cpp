/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
*/

//Brute Force: using for loop from 0 to <n and then checking for every element if it is celebrity or not
//Approach 2: Using Stacks: pushing all persons in the stack and then pop two persons at a time, the one person who doesn't know the other should be pushed back to the stack. Repeat the same process till you get a single element. Now check if the last remaining person is celebrity or not i.e. he knows no one and all knows him
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        //pushing all persons to stack s
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        int A, B;
        while(s.size()>1){
            A = s.top(); s.pop();
            B = s.top(); s.pop();
            
            if(M[A][B] == 0){
                s.push(A);
            }
            else{
                s.push(B);
            }
            
        }
        int celeb = s.top();
        
        for(int i =0; i<n; i++){
            if(M[i][celeb]==0 && i!=celeb){
                return -1;
            }
            
            if(M[celeb][i]){
                return -1;
            }
        }
        
        return celeb;
    }
};