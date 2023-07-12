#include<iostream>
#include<queue>
#include<limits.h>
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

class NodeData{
  public:
    int size;
    int maxval;
    int minval;
    bool valid;
    NodeData(int size, int maxval, int minval, bool valid){
        this->size = size;
        this->maxval = maxval;
        this->minval = minval;
        this->valid = valid;
    }
    NodeData(){
      size = 0;
      maxval = INT_MIN;
      maxval = INT_MAX;
      valid = true;
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

//helper function for findint the largest BST in BT
NodeData* helper(Node* root, int &ans){
        //Base case
        if(root == NULL){
            NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
            return temp;
        }
        
        //finding answers for left and right subtree: following bottom up approach
        auto leftans = helper(root->left, ans);
        auto rightans = helper(root->right, ans);
        
        NodeData* currnode = new NodeData();
        
        currnode->size = leftans->size + rightans->size + 1;
        currnode->maxval = max(leftans->maxval, rightans->maxval);
        currnode->minval = min(leftans->minval, rightans->minval);
        
        //when current root data is larger than largest value of left subtree and smaller then smallest value of right subtree then it is a valid bst
        if(leftans && rightans && (leftans->maxval < root->data && rightans->minval > root->data))
            currnode->valid = true;
        else 
            currnode->valid = false;
        
        if(currnode->valid)
            ans = max(ans, currnode->size);
        
        return currnode;
    }
    
    
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	
    	int ans = 0;
    	helper(root, ans);
    	return ans;
    }

//main function
int main(){
    int val;

    Node* root = buildTree();

    cout<<"Printing the Tree:\n";
    levelOrderTraversal(root);

    cout<<"Largest BST is of size: "<<largestBst(root);
}

 