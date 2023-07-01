/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;

        while(curr){
            //if left is null visit or push the current node
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }

            //if left node exists
            else{
                TreeNode* pred = curr->left;
                while(pred->right != nullptr && pred->right != curr ){
                    pred = pred->right;
                }

                //when pred right node is null
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }

                //when pred right node is not null, remove the link and push curr data
                else{
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }   