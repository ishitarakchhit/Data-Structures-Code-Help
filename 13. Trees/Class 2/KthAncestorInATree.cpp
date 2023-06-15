/*
Given a binary tree of size  N, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note: It is guaranteed that the node exists in the tree.


Example 1:



Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
 

Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1<=N<=104
1<= K <= 100
*/

bool func(Node* root, int &k, int node, int &ans){
    //Bc
    if(root == NULL)
        return false;

    //when you have found the node return true 
    if(root->data == node)
        return true;

    //to find node in left and right part of root 
    bool leftAns = func(root->left, k, node, ans);
    bool rightAns = func(root->right, k, node, ans );
    
    //if you have found node in either part decrement k so that you reach to kth ancestor //backtracking 
    if(leftAns || rightAns)
        k--;

    //When you have reached to Kth ancestor mark k as -1 so that when it moves to other part with k =0 it does not store another node's value 
    if(k==0){
        ans = root->data;
        k=-1;
    }

    //to return true if found in either part or return false if not found
    return leftAns||rightAns;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    func(root, k, node, ans);
    return ans;
}