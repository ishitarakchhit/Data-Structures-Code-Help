/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
*/

class Solution {
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        return max(op1, max(op2, op3));
    }
};