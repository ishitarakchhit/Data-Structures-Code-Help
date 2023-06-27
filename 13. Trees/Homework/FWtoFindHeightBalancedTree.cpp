/*
Given a binary tree, determine if it is 
height-balanced
.

 

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
    
bool isbalanced = true;
int maxDepth(TreeNode* root){
        if(root == NULL)
            return 0;
        
        //to calculate the height of left and right nodes
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);

        if(isbalanced && abs(leftheight- rightheight) > 1)
            isbalanced = false;

        //to calculate the max depth + 1(to consider the current node)
        int ans = max(leftheight, rightheight) + 1;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        maxDepth(root);

        return isbalanced;
        
    }
};