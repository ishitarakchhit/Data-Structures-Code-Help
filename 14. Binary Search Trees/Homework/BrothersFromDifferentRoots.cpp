/*
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x. Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.


Example 1:

Input:
BST1:
       5
     /   \
    3     7
   / \   / \
  2   4 6   8

BST2:
       10
     /    \
    6      15
   / \    /  \
  3   8  11   18

x = 16
Output:
3
Explanation:
The pairs are: (5, 11), (6, 10) and (8, 8)
 

Example 2:

Input:
BST1:
  1
   \
    3
   /
  2
BST2:
    3
   / \
  2   4
 /     
1

x = 4
Output:
3
Explanation:
The pairs are: (2, 2), (3, 1) and (1, 3)

Your Task:
You don't need to read input or print anything. Your task is to complete the function countPairs(), which takes 2 BST's as parameter in form of root1 and root2 and the integer x, that returns the count of all pairs from both the BSTs whose sum is equal to x.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/


int count = 0;
    
    bool searchval(Node* root, int key){
        //we have to seach the value x-root1
        if(root == NULL)
            return false;
        
        bool leftans = false;
        bool rightans = false;
        if(root ->data == key)
            return true;
        if(root->data > key)
            leftans = searchval(root->left, key);
        else
            rightans = searchval(root->right, key);
        
        return leftans || rightans;
    }
    void helper(Node*root1, Node* root2, int x){
    
        if(root1 == NULL)
            return;
        
        if(searchval(root2, x-root1->data))
            count ++;
        helper(root1->left, root2, x);
        helper(root1->right, root2, x);
        return;
        
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        helper(root1, root2, x);
        return count;
    }