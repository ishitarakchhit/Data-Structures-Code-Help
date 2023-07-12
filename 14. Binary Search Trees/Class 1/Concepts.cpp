#include<iostream>
#include<queue>
#include<limits>
using namespace std;

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

//function to create BST
Node* createBST(Node* root, int data){
    //if we are creating the first node
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    // if we are not creating the first node
    if(root->data > data){
        root->left = createBST(root->left, data);
    }

    else{
        root->right = createBST(root->right, data);
    }
    return root;
}

//to take input as data to create a BST
void takeInput(Node* &root){
    int data;
    cin>> data;
    while(data != -1){
        root = createBST(root, data);
        cin>> data;
    }
    return;
}


// to traverse the BST in level order
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){

        Node* temp = q.front();
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

//pre post and inorder traversal remains same as tree 


//to search for a node in BST
bool searchBST(Node* root, int val){
    if(root == NULL){
        return false;
    }

    if(root->data == val)
        return true;

    if(root->data > val)
        searchBST(root->left, val);
    else
        searchBST(root->right, val);
    
}


//function to find minimum value of BST 
int minVal(Node* root){
    
    while(root->left){
        root = root->left;
    }
    return root->data;
}


//main function
int main(){
    Node* root = NULL;
    int val;

    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);

    cout<<"Enter the value to be searched: ";
    cin>>val;
    cout<<searchBST(root, val);

    cout<<endl<<"The minimum value of BST is: ";
    cout<<minVal(root);
}