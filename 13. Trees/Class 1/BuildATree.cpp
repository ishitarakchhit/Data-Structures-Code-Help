#include<iostream>
#include<queue>
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


//function to print a tree in level order traversal
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


//function to print a tree in in order traversal
void inOrderTraversal(Node* root){
    if(root == NULL)
        return;
    
    //LNR
    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);
    
}


//function to print a tree in preorder traversal
void preOrderTraversal(Node* root){
    if(root == NULL)
        return;
    
    //NLR
    cout<<root->data<<" ";

    inOrderTraversal(root->left);

    inOrderTraversal(root->right);
    
}


//function to print a tree in post order traversal LRN
void postOrderTraversal(Node* root){
    if(root == NULL)
        return;
    
    //LRN
    inOrderTraversal(root->left);

    inOrderTraversal(root->right);

    cout<<root->data<<" ";
    
}



int main(){

    //to create a node
    Node* root = NULL;

    //to build a tree
    root = buildTree();

    //to print a tree using level order traversal
    cout<<endl<<"Level Order Traversal is: "<<endl;
    levelOrderTraversal(root);

    //to print a tree using inorder traversal
    cout<<endl<<"In Order Traversal is: "<<endl;
    inOrderTraversal(root);

    //to print a tree using preorder traversal
    cout<<endl<<"Pre Order Traversal is: "<<endl;
    preOrderTraversal(root);

    //to print a tree using postorder traversal
    cout<<endl<<"Post Order Traversal is: "<<endl;
    postOrderTraversal(root);


    return 0;
}


