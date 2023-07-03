/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

                                               

Example 1:

Input:
     11
    /  \
   1    2
Output: 11
Explanation: The maximum sum is sum of
node 11.
Example 2:

Input:
        1
      /   \
     2     3
    /     /  \
   4     5    6
Output: 16
Explanation: The maximum sum is sum of
nodes 1 4 5 6 , i.e 16. These nodes are
non adjacent.
Your Task:
You don't need to read input or print anything. You just have to complete function getMaxSum() which accepts root node of the tree as parameter and returns the maximum sum as described.

Expected Time Complexity: O(Number of nodes in the tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes in the tree ≤ 10000
1 ≤ Value of each node ≤ 100000
*/



pair<int, int> getMaxSumHelper(Node* root){
        if(root == NULL){
            return {0, 0};
        }
        
        auto left = getMaxSumHelper(root->left);
        auto right = getMaxSumHelper(root->right);
        
        //sum including the current node
        int a = root->data + left.second + right.second;
        
        //sum excluding the current node
        int b = max(left.first, left.second) + max(right.first, right.second);
        
        return {a,b};
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        
        pair<int, int> ans = getMaxSumHelper(root);
        
        return max(ans.first, ans.second);
    }