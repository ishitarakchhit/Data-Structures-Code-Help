/*
Given a binary tree, determine if it is 
height-balanced
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

class Solution {
    
//function to caluclate the height of tree from root node
int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        
        //to calculate the height of left and right nodes
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);

        //to calculate the max depth + 1(to consider the current node)
        int ans = max(leftheight, rightheight) + 1;

        return ans;
    }
public:
    //function to check if given tree is balanced or not
    bool isBalanced(TreeNode* root) {
        
        //BC
        if(root == NULL)
            return true;

        //if tree is not balanced at root node then return false
        bool ans = abs(maxDepth(root->left) - maxDepth(root->right) >1
        
        //to check if tree is balanced at root node as well as left and right part of root nodes
        return ans && isBalanced(root->left) & isBalanced(root->right);
        
    }
};