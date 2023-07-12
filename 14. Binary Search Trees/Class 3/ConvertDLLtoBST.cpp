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


//helper function for converting tree to DLL
void helper(Node* root, Node* &head){
        if(root == NULL)
            return;
        
        helper(root->right, head);
        
        root->right = head;
        
        if(head)
            head->left = root;
        
        head = root;
        
        helper(root->left, head);
    }



//Function to convert binary tree to doubly linked list and return it.
Node * bToDLL(Node *root)
    {
    Node* head= NULL;
    helper(root, head);
    return head;
    }


void printDLL(Node* root){
    cout<<endl;
    while(root){
        cout<<root->data<<" ";
        root = root->right;
    }
    return;
}


//function to convert doubly linked list to binary search tree
Node* DLLtoBST( Node* &head, int n){
    if(n <=0 || head == NULL) 
        return NULL;
    
    Node* leftsubtree = DLLtoBST(head, n -1 -n/2);
    Node* root = head;
    root->left = leftsubtree;
    head = head->right;

    root->right = DLLtoBST(head, n/2);
    return root;

}



//main function
int main(){
    Node* root = NULL;
    int val;
    int n;
    cin>>n;
    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);

    bToDLL(root);
    cout<<"Printing the DLL";
    printDLL(root);

    Node* root1 = NULL;
    root1 = DLLtoBST(root, n);
    cout<<endl<<"Printing the Tree:\n";
    levelOrderTraversal(root1);

    
}