int findSucc(BinaryTreeNode<int>* root, int key, int &ans){
    if(root == NULL)
        return ans;

    if(root->data <= key){
        return findSucc(root->right, key, ans);
    }

    else
        ans = root->data;
        return findSucc(root->left, key, ans);
    
}


int Successor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int ans = -1;
    int succ = findSucc(root, key, ans);

    return ans;
}
