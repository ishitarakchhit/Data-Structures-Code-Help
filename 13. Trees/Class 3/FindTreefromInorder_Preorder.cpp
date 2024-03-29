#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

//function to find position of a particular element
int findPosition(int inorder[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(inorder[i] == element)
            return i;
    }
    
}


//function to construct a tree when inorder and preorder traversals are given
node* findTree(int inorder[], int preorder[], int size, int &preIndex, int starIndex, int endIndex){
    if(preIndex>=size || starIndex> endIndex)
        return NULL;

    int element = preorder[preIndex++];
    node* root = new node(element);
    int pos = findPosition(inorder, size, element);

    root->left = findTree(inorder, preorder, size, preIndex, starIndex, pos-1);
    root->right = findTree(inorder, preorder, size, preIndex, pos+1, endIndex);

}


//function to print a tree in level order traversal
void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{

        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        }
        
    }
    return;
}



int main(){
    int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    int preorder[] = {10, 20, 40, 50, 30, 60, 70};
    int size = 7;
    int preIndex = 0;
    int startIndex = 0;
    int endIndex = size-1;

    node* root = findTree(inorder, preorder, size, preIndex, startIndex, endIndex);

    cout<<"Level Order Traversal is: \n";
    levelOrderTraversal(root);
}