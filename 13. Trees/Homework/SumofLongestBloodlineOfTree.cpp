/*
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 104
*/


//Apprach: similar to diameter of tree where we find height and return the max sum left and right subtree
pair<int, int> solve(Node* root){
        
        if(root == NULL)
            return {0,0};
        
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // make pair with larger height
        if(left.first > right.first)
            return { left.first+1, left.second + root->data };
        
        //make pair with larget height
        else if(left.first <right.first)
            return { right.first+1, right.second + root->data };
        
        //if both are same make pair with larger sum
        else
            return { left.first+1, max(left.second, right.second) + root->data };
    }
        
        
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        auto ans = solve(root);
        return ans.second;
    }




//My approach: 
    int maxsum = 0;
    int maxcount = 0;
    
    void solve(Node* root, int &sum, int count){
        if(root == NULL)
            return;
        
        sum+= root->data;
        
        //check for leaf node
        if(root->left == NULL && root->right == NULL){
            if(count > maxcount){
                maxsum = sum;
                maxcount = count;
            }
            else if(count == maxcount){
                maxsum = max(maxsum, sum);
            }
            //cout<<maxsum;
        }
        
        solve(root->left, sum, count+1);
        solve(root->right, sum, count +1);
        sum-= root->data;
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum = 0;
        int count = 0;
        solve(root, sum, count);
        return maxsum;
    }
