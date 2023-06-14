/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/


int func(TreeNode* root){
        if(root == NULL)
            return 0;
        
        //to calculate the height of left and right nodes
        int leftheight = func(root->left);
        int rightheight = func(root->right);

        //to calculate the max depth + 1(to consider the current node)
        int ans = max(leftheight, rightheight) + 1;

        return ans;
    }
