#include<iostream>
#include<queue>
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

Node* buildTree(){
    int data;
    cout<<"\nEnter the data";
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

void levelOrderTraversal(Node* root){
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* temp = q.front();
        if(temp == root)
            cout<<endl;
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right){

            q.push(temp->right);
        cout<<endl;
        }
    }
    return;
}

int main(){

    //to create a node
    Node* root = NULL;

    //to build a tree
    root = buildTree();

    //to print a tree using level order traversal
    levelOrderTraversal(root);


    return 0;
}


