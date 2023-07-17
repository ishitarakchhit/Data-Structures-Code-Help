/*
Problem Description
 
 

You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.

Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.



Problem Constraints
1 <= A[i] <= 106

1 <= |A| <= 105



Input Format
First and only argument is an integer array A denoting the pre-order traversal.



Output Format
Return an integer:

0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST


Example Input
Input 1:

A = [7, 7, 10, 10, 9, 5, 2, 8]


Example Output
Output 1:

 0
*/

//Approach: using BST property

void insertBST(vector<int> &A, int &i, int min, int max){
    if(i == A.size())
        return;
    
    if(A[i] < max && A[i] > min){
        int rootData = A[i++];
        insertBST(A, i, min, rootData);
        insertBST(A, i, rootData, max);
    }
    
}
int Solution::solve(vector<int> &A) {
    int min = 0;
    int max = INT_MAX;
    int i =0;
    insertBST(A, i, min, max);
    return i==A.size();
}