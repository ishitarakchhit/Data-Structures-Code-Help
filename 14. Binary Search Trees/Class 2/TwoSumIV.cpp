/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105
*/


void findInorder(TreeNode* root, vector<int> &inorder){
        if(root==NULL)
            return;
        
        findInorder(root->left, inorder);

        inorder.push_back(root->val);

        findInorder(root->right, inorder);

    }

    bool twoSum(vector<int> inorder, int target){
        int i=0; 
        int j=inorder.size()-1;

        while(i<j){
            if(inorder[i] + inorder[j] > target)               //going to a lower value
                j--;
            else if(inorder[i] + inorder[j] < target)          // going to a higher value
                i++;
            else
                return true;
        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;

        //to find the inordertraversal of BST
        findInorder(root, inorder);

        return twoSum(inorder, k);


    }