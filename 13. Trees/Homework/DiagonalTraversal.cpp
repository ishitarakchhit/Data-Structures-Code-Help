/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
unnamed
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4
Your Task:
You don't need to read input or print anything. The task is to complete the function diagonal() that takes the root node as input argumets and returns the diagonal traversal of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Here N is number of nodes.

Constraints:
1 <= Number of nodes<= 105
1 <= Data of a node<= 105
*/

//Approach 1: using map
void solve(Node* root, map<int, vector<int>> &mp, int distance){
    if(root == NULL)
        return;
    
    mp[distance].push_back(root->data);
    //to call the left subtree
    solve(root->left, mp, distance+1);
    solve(root->right, mp, distance);
}

vector<int> diagonal(Node *root)
{
   // your code here
   map<int, vector<int>> mp;
   int distance = 0;
   //mp[distance].push_back(root->data);
   
   solve(root, mp, distance);
   vector<int> ans;
   
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            ans.push_back(it->second[i]);
        }
    }
   return ans;
}









//Approach 2: using stack and level order traversal
