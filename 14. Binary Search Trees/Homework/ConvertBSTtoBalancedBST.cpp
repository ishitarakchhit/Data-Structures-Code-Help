/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

Example 1:


Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
Example 2:


Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105
*/


//function to store inorder traversal of binary search tree
    void storeInorder(TreeNode* root, vector<int> &inorder){
        if(root == NULL)
            return;
        
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    //function to create balanced bst using inorder traversal
    TreeNode* createBST( vector<int> inorder, int s, int e){
        if(s>e)
            return NULL;
        
        int mid = s+(e-s)/2;

        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = createBST(inorder, s, mid-1);
        root->right = createBST(inorder, mid+1, e);
        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;

        storeInorder(root, inorder);
        return createBST(inorder, 0, inorder.size()-1);

        return root;

    }