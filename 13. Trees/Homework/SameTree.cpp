/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
*/

//function to check symmetry for two trees
    bool isSame(TreeNode* p, TreeNode* q){
        if((p == NULL && q!= NULL) || ( p!= NULL && q == NULL))
            return false;

        else if(q== NULL && p== NULL)
            return true;
            
        else if(p->val != q->val)
            return false;
        //when data of both node are equal check for further nodes
        else{
            bool leftAns = isSame(p->left, q->right);
            bool rightAns = isSame(p->right, q->left);
            //if left part is symmetric but right part isn't so return false same for right and left
            return leftAns & rightAns;
        }
    }

