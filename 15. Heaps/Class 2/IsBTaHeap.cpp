

pair{bool, int} checkHeap(Node* root){
    if( root == NULL)
        return make_pair(true, INT_MIN);

    auto leftAns = checkHeap(root->left);
    auto rightAns = checkHeap(root->right);

    if(leftAns.first && rightAns.first && leftAns.second < root->data && rightAns.second < root->data){
        return make_pair(true, root->data);
    }
    else   
        return make_pair(false, root->data);
}