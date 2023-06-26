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

//function to print right view of a tree
void rightView(Node* root, int level, vector<int> &ans){
    //B.C.
    if(root == NULL)
        return;
    
    //Whenever level becomes equal to ans size store the root value 
    if(level == ans.size())
        ans.push_back(root->data);

    //right tree call
    rightView(root->right, level+1, ans);

    //left tree call 
    rightView(root->left, level+1, ans);
}


//main function
int main(){
    Node* root = buildTree();
    vector<int> ans;
    int level = 0;
    
    rightView(root, level, ans);

    for(auto i: ans)
        cout<<i<<"\t";
    return 0;
}
