int findPred(BinaryTreeNode<int>* root, int key, int &ans){
    if(root == NULL)
        return ans;

    if(root->data < key){                                      //when you've found a smaller value then store it since it might be a pred to key. Then move to right of that node
        ans = root->data;
        return findPred(root->right, key, ans);
    }

    else
        return findPred(root->left, key, ans);                 //otherwise move to left for finding a smaller value
    
}

int findpredecessorinBST(BinaryTreeNode<int>* root, int key){
     int ans = -1;
    int pred = findPred(root, key, ans);

    return ans;
}