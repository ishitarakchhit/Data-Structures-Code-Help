#include<iostream>
#include<vector>
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
//function to store the inorder traversal of BST
void inorderTraversal(Node* root, vector<int> &inorder){
    if(root == NULL)
        return;
    
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}


//function to check if a given tree is a CBT or not 
//Using level order traversal to store nodes in a queue and count the position of last node and total no. of nodes in the tree, if they are same then it is a CBT
bool checkifCBT(Node* root){
    if(root == NULL)
        return true;

    int flag = false;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* frontnode = q.front();
        q.pop();
        
        if(frontnode == nullptr){
            flag = true;                   //flag that we have found a null value
        }
        else{
            if(flag){                       //this means that we have encountered a null value before a valid node data
                return false;
            }
            q.push(frontnode->left);
            q.push(frontnode->right);
        }

    }
    return true;


}


//main function
int main(){
    Node* root = NULL;
    int val;

    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);

    checkifCBT(root) ? cout<<"\nGiven Tree is a CBT": cout<<"\nGiven Tree is not a CBT";
    
}