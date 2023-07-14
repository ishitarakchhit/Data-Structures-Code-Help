/*
Given a Binary Search Tree that contains positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means, we are not able to insert any element after that node.

Example 1:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : 
Yes
Explanation : 
Node "1" is the dead End because after that 
              we cant insert any element.
Example 2:

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : 
Yes
Explanation : 
We can't insert any element at 
              node 9.   
Your Task:
You don't have to input or print anything. Complete the function isDeadEnd() which takes the input parameter head and returns a boolean value.

Expected Time Complexity: O(N) where N is the Number of nodes in a given binary tree.
Expected Space Complexity: O(N)

Constraints:
1<=T<=100
1<=N<=200
*/

//My approach: 
bool helper(Node* root, int min, int max){
    if(root == NULL){
        
            return true;
    }
    
    if(root->left == NULL && root->right == NULL){
        if(min+1 == root->data && root->data+1 == max)
            return false;
    }
    bool leftAns = helper(root->left, min, root->data);
    bool rightAns = helper(root->right, root->data, max);
    
    return leftAns && rightAns;
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    int min = 0;
    int max = INT_MAX;
    
    return !helper(root, min, max);
}


//Another approach: using map to map the visited nodes, when visiting a node, search for node a root->data+1 and root->data-1