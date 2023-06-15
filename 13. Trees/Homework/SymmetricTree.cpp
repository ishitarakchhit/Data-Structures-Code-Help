/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

class Solution {
    //function to check symmetry for two trees
    bool checkSymmetric(TreeNode* p, TreeNode* q){
        if((p == NULL && q!= NULL) || ( p!= NULL && q == NULL))
            return false;

        else if(q== NULL && p== NULL)
            return true;
            
        else if(p->val != q->val)
            return false;
        //when data of both node are equal check for further nodes
        else{
            bool leftAns = checkSymmetric(p->left, q->right);
            bool rightAns = checkSymmetric(p->right, q->left);
            //if left part is symmetric but right part isn't so return false same for right and left
            return leftAns & rightAns;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        //to break the tree in two parts left and right then check for symmetry
        TreeNode* p = root->left;
        TreeNode* q = root->right;

        return checkSymmetric(p, q);
    }
};