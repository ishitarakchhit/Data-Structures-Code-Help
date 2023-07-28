/*
Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.

Example 1:

Input:
      5
    /  \
   2    3
Output: 1
Explanation: The given tree follows max-heap property since 5,
is root and it is greater than both its children.

Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 0

Your Task:
You don't need to read input or print anything. Your task is to complete the function isHeap() which takes the root of Binary Tree as parameter returns True if the given binary tree is a heap else returns False.

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)

Constraints:
1 ≤ Number of nodes ≤ 100
1 ≤ Data of a node ≤ 1000
*/

class Solution {
  public:
  
  //function to count the total number of nodes
    int countNodes(struct Node* tree){
        if(tree == NULL)
            return 0;
        
        int leftsum = countNodes(tree->left);
        int rightsum = countNodes(tree->right);
        return leftsum+rightsum+1;
    }
    
    //function to check if given tree is complete binary tree or not
    bool checkCBT(struct Node* root, int index, int &totalnodes){
        if(root == NULL)
            return true;
        
        if(index > totalnodes)
            return false;
        
        bool leftans = checkCBT(root->left, index*2, totalnodes);
        
        bool rightans = checkCBT(root->right, index*2 +1, totalnodes);
        
        return leftans && rightans;
    }
    
    
    //function to check if property of heap parent>child
    pair<bool, int> checkHeap(struct Node* root){
        if(root == NULL)
            return make_pair(true, INT_MIN);
        
        auto leftans = checkHeap(root->left);
        auto rightans = checkHeap(root->right);
        
        if(leftans.first && rightans.first && leftans.second < root->data && rightans.second <root->data)
            return make_pair(true, root->data);
        else
            return make_pair(false, root->data);
    }

    bool isHeap(struct Node* tree) {
        int totalNodes = countNodes(tree);
        
        bool isCBT = checkCBT(tree, 1, totalNodes);
        
        if(!isCBT)
            return false;
        
        return checkHeap(tree).first;
        
    }
};