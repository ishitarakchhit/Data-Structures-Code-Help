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
node* findTree(int inorder[], int postorder[], int size, int &postIndex, int starIndex, int endIndex){
    if(postIndex<0 || starIndex> endIndex)
        return NULL;

    int element = postorder[postIndex--];
    node* root = new node(element);
    int pos = findPosition(inorder, size, element);

    root->right = findTree(inorder, postorder, size, postIndex, pos+1, endIndex);
    root->left = findTree(inorder, postorder, size, postIndex, starIndex, pos-1);

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
    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};
    int size = 6;
    int postIndex = size-1;
    int startIndex = 0;
    int endIndex = size-1;

    node* root = findTree(inorder, postorder, size, postIndex, startIndex, endIndex);

    cout<<"Level Order Traversal is: \n";
    levelOrderTraversal(root);
}