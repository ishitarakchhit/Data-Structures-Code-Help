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

void printLL(Node* head){

    while(head){
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl;
}


void convertBSTtoLL(Node* root, Node* &head){
    if(root == NULL)
        return;
    
    convertBSTtoLL(root->right, head);
    if(head){
        head->left = NULL;
        root->right = head;
    }

        head = root;

        convertBSTtoLL(root->left, head);

    return;
    
}


//converting BST to LL using another appraoch: traversing inorderwise using recursion and simultaneously attaching right pointers. Used dummy node initially
void convertBSTtoLL2(Node* root, Node* &dummy, Node* &prev){
    if(root == NULL)
        return;
    
    convertBSTtoLL2(root->right, dummy, prev);
    if(root){
        prev->right = root;
         prev->left = NULL;
    }
    
    prev = root;
    convertBSTtoLL2(root->left, dummy, prev);
}

//main function
int main(){
    Node* root = NULL;
    int val;

    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);


    //using appraoch 1(my appraoch)
    // Node* newroot = NULL;
    // convertBSTtoLL(root, newroot);
    // cout<<"Printing the Linked List:\n";
    // printLL(newroot);

    //using another approach
    Node* newroot2 = new Node(-1);
    Node* prev = newroot2;
    convertBSTtoLL2(root, newroot2, prev);
    prev->left = NULL;
    prev->right = NULL;
    cout<<"Printing the Linked List using another approach:\n";
    printLL(newroot2->right);
}