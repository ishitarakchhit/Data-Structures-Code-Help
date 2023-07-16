/*
32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}
Explanation: 
The least next greater element of 8 is 18.
The least next greater element of 58 is 63 and so on.

Example 2:

Input:
arr[] = {2, 6, 9, 1, 3, 2}
Output: {3, 9, -1, 2, -1, -1}
Explanation: 
The least next greater element of 2 is 3. 
The least next greater element of 6 is 9.
least next greater element for 9 does not
exist and so on.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLeastGreater() which takes an array arr[] of size N and returns a list as an output.

Expected Time Complexity: O(N* log N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= A[i] <= 105
*/

//Approach1: using two nested loops
//approach2: using BST: traversing the array and simultaneously forming a BST finding the inorder successor for each given element in the array

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    public:
    
    Node* insertBST(Node* &root, int element, int &succ){
        if(root == NULL){
            root = new Node(element);
            return root;
        }
        
        if(root->data > element){
            succ = root->data;
            root->left = insertBST(root->left, element, succ);
        }
        else{
            root->right = insertBST(root->right, element, succ);
        }
        return root;
    }
    
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n);
        Node* root = NULL;
        for(int i = arr.size()-1; i>=0; i--){
            int succ = -1;
            insertBST(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};