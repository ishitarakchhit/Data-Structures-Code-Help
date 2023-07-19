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


//Copy values in BST in postorder from
void copyinpost(Node* &root, vector<int> inorder, int &i){
    if(root == NULL)
        return;
    
    copyinpost(root->left, inorder, i);
    copyinpost(root->right, inorder, i);

    root->data = inorder[i++];
}


//function to convert BST to max heap
Node* convertBSTtoHeap(Node* &root){
    //store the inorder traversal in an array
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int i =0;
    //now copy the values in the BST in postorder form
    copyinpost(root, inorder, i);
    return root;

}


//main function
int main(){
    Node* root = NULL;
    int val;

    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);

    cout<<"Printning the heap:\n";
    convertBSTtoHeap(root);
    levelOrderTraversal(root);
    
}