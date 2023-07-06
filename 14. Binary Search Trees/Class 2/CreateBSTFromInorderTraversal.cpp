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


Node* createBSTfromInorder(int inorder[], int s, int e){
    if(s> e)
        return NULL;
    
    int mid = s + (e-s)/2;
    Node* root = new Node(inorder[mid]);

    root->left = createBSTfromInorder(inorder, s, mid-1);
    root->right = createBSTfromInorder(inorder, mid+1, e);

}
//main function
int main(){
    int inorder[5] = {10, 20, 30, 40, 50};
    Node* root = createBSTfromInorder(inorder, 0, 4);

    levelOrderTraversal(root);
}