#include<iostream>
#include<vector>
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


void leftView(Node* root, int level, vector<int> &ans){
    //B.C.
    if(root == NULL)
        return;
    
    //Whenever level becomes equal to ans size store the root value 
    if(level == ans.size())
        ans.push_back(root->data);

    //left tree call 
    leftView(root->left, level+1, ans);

    //right tree call
    leftView(root->right, level+1, ans);

}


int main(){
    Node* root = buildTree();
    vector<int> ans;
    int level = 0;
    
    leftView(root, level, ans);

    for(auto i: ans)
        cout<<i<<"\t";
    return 0;
}
