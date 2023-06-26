#include<iostream>
using namespace std;

//class to define a Node
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


//function to build a tree
Node* buildTree(){
    int data;
    cout<<"\nEnter the data: ";
    cin>>data;

    //base case
    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    
    root->left = buildTree();

    root->right = buildTree();

    return root;
}



//function to print left boundary
void printLeftBoundary(Node* root){
    //Base case to check for last node and leaf nodes (stop when leaf case is found)
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    cout<<root->data<<" ";

    if(root->left)
        printLeftBoundary(root->left);
    else  
        printLeftBoundary(root->right);
}


//function to print leaf boundary
void printLeafBoundary(Node* root){
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
    
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}


//function to print right boundary
void printRightBoundary(Node* root){
    //Base case to check for last node and leaf nodes (stop when leaf case is found)
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right)
        printLeftBoundary(root->right);
    else  
        printLeftBoundary(root->left);

    //to print in reverse order that is why print after RCs
    cout<<root->data<<" ";
}


void boundaryTraversal(Node* root){
    if(root == NULL){
        return;
    }

    //to print left boundary
    printLeftBoundary(root);

    //to print leaf boundary
    printLeafBoundary(root);

    //to print right boundary
    printRightBoundary(root->right);
}

int main(){
    Node* root = buildTree();
    
    boundaryTraversal(root);

    return 0;
}
