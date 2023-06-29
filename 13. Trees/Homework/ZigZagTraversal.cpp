/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100
 
*/



vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool LtoR = true;
        queue<TreeNode*> q;

        if(!root)
            return ans;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            //loop to push elements into level array until current size of queue 
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                q.pop();
                int index;
                //if LtoR is true insert elements in LtoR order otherwise in reverse order
                index = LtoR==true? i : size-i-1;
                level[index] = front->val;

                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
                
            ans.push_back(level);
            LtoR = !LtoR;
        }
        return ans;

    }








//My code 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> output;
        vector<vector<int>> ans;

        if(!root)
            return ans;

        q.push(root);
        q.push(NULL);
        int order = 0;

        while(!q.empty()){
            //Take out the front element from queue
            TreeNode* temp = q.front();
            q.pop();

            //Whenever you encounter NULL in queue push another NULL if queue is not empty and push the elements uptil now into ans vector (if order is odd then reverse the elements before pushing)
            if(temp == NULL){

                if(order&1){
                    reverse(output.begin(), output.end());
                }

                if(output.size()>0)
                    ans.push_back(output);
                output={};
                order++;

                if(!q.empty()){
                    q.push(NULL);
                }
                
            }

            else{
                output.push_back(temp->val);
 
                if(temp->left) 
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }