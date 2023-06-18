/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/


class Solution {
    //function to check whether the path is equal to target sum or not 
    bool checkSum(vector<int> path, int targetSum){
        int sum =0;

        for(int i=0; i<path.size(); i++){
            sum = sum+path[i];
        }
        
        return sum == targetSum;
    }

    //function to find path sum 
    void solve(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &path){
        //Base Case
        if(root == NULL){
            return;
        }

        //to push root value into path array
        path.push_back(root->val);

        //if the current node is a leaf node and sum is equal to target sum then push path into ans array
        if(root->left == NULL && root->right == NULL && checkSum(path, targetSum))
            ans.push_back(path);
    
        //R.C.
        solve(root->left, targetSum, ans, path);
        solve(root->right, targetSum, ans, path);
        //Backtrack
        path.pop_back();
        
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if(root == NULL && targetSum ==0){
            return ans;
        }

        solve(root, targetSum, ans, path);
        return ans;
    }
};