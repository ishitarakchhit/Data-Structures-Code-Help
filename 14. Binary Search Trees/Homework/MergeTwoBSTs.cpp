/*
Given two BSTs, return elements of both BSTs in sorted form.


Example 1:

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: 
After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.
Example 2:

Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: 
After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.

Your Task:
You don't need to read input or print anything. Your task is to complete the function merge() which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.


Expected Time Complexity: O(M+N) where M and N are the sizes of the two BSTs.
*/



vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       
       stack<Node*> s1, s2;
       Node* a = root1;
       Node* b = root2 ;
       vector<int> ans;
       
       while(a || b || !s1.empty() || !s2.empty()){
           while(a){
               s1.push(a);
               a = a->left;
           }
           while(b){
               s2.push(b);
               b = b->left;
           }
           
            
            
            if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)){
                auto atop = s1.top();
                ans.push_back(atop->data);
                s1.pop();
                a = atop->right;
            }
            else{
                auto btop = s2.top();
                ans.push_back(btop->data);
                s2.pop();
                b = btop->right;
            }
       }
       
       
       return ans;
    }