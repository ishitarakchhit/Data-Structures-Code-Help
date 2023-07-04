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

//pre post and inorder traversal remains same as tree 


//to search for a node in BST and returns it
Node* searchBST(Node* root, int val){
    if(root == NULL){
        return NULL;
    }

    if(root->data == val)
        return root;

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

//function to find maximum value node of BST
Node* maxVal(Node* root){
    while(root->right){
        root = root->right;
    }
    return root;
}

Node* deleteInBST(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        //perfrom the 4 cases

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right){
            Node* child = root->right;
            return child;
        }
        else if(root->left && root->right == NULL){
            Node* child = root->left;
            return child;
        }
        else{
            Node* child = maxVal(root->left);
            root->data = child->data;
            root->left = deleteInBST(root->left, child->data);
            return root;
        }
    }

    else if(root->data > key){
        root->left = deleteInBST(root->left, key);
    }
    else{
        root->right = deleteInBST(root->right, key);
    }
}





//main function
int main(){
    Node* root = NULL;
    int val;

    takeInput(root);

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);                   // to print level order traversal  of BST

    cout<<"Enter the node to be deleted: ";
    cin>>val;
    deleteInBST(root, val);                      // to delete a node in BST

    cout<<"Printing the new Tree:\n";
    levelOrderTraversal(root);                   // to print level order traversal of BST

    return 0;
}