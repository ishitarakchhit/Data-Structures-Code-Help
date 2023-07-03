/*
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
*/

//Approach: MOrris Traversal Modification
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        if(root == NULL){
            return;
        }

        while(curr){
            //if(curr->left does not exisits)
            if(curr->left == NULL){
                curr = curr->right;
            }
            //left of curr exists
            else{
                TreeNode* pred = curr->left;
                while(pred->right){
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
        
        return;
    }



    //My approach using queue
    void solve(TreeNode* root, queue<TreeNode*> &q){
        if(root == NULL)
            return;
        
        TreeNode* temp = root;
        q.push(temp);
        solve(root->left, q);
        solve(root->right, q);

    }

    void flatten(TreeNode* root) {
        queue<TreeNode*> q;

        if(root == NULL){
            return;
        }

        solve(root, q);
        root->left = NULL;
        root->right = NULL;
        int count = 0;
        TreeNode* temp = q.front();
        q.pop();
        while(!q.empty()){
            temp->right = q.front();
            q.pop();
            temp = temp->right;
            temp->right = NULL;
            temp->left= NULL;
            
        }
        
        return;
    }