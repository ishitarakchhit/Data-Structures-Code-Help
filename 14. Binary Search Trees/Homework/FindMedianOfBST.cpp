/*
Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.

Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
Median of the BST is:

If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
If number of nodes are odd : then median = (N+1)/2th node.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1<=N<=10000
*/

int morrisTraversal(struct Node *root){
    int count =0;
    
    Node* curr = root;
    while(curr){
        if(!curr->left){
            count++;
            curr=curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            
            if(pred->right == curr){
                pred->right = NULL;
                curr = curr->right;
                count ++;
            }
            else{
                pred->right = curr;
                curr= curr->left;
            }
        }
    }
    return count;
}

int morrisFind(struct Node *root, int midcount){
    int count =0;
    int value = 0;
    Node* curr = root;
    while(curr){
        if(!curr->left){
            count++;
            if(count == midcount)   value = curr->data;
            curr=curr->right;
        }
        else{
            Node* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred = pred->right;
            }
            
            if(pred->right == curr){
                pred->right = NULL;
                count ++;
                if(count == midcount)   value = curr->data;
                curr = curr->right;
            }
            else{
                pred->right = curr;
                curr= curr->left;
            }
        }
    }
    return value;
}

float findMedian(struct Node *root)
{
      //Code here
    int totalnodes = morrisTraversal(root);
    int mid1 = 0;
    int mid2 = 0;
    
    mid1 = morrisFind(root, (totalnodes+1)/2);
    if( !(totalnodes & 1 ))
        mid2 = morrisFind(root, (totalnodes+2)/2);  
    else
        mid2=mid1;
    
    //cout<<"Mid1 is: "<<mid1;
    //cout<<endl<<"Mid2 is: "<<mid2<<endl;
        return (float)(mid1+mid2)/2;
}