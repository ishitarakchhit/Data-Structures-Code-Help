#include<iostream>
#include<queue>
#include<map>
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


void topView(Node* root){
    queue<pair<Node*, int>> q;                   //pair.first to store node and second to store distance
    map<int, int> topnode;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        Node* temp = q.front().first;
        int distance = q.front().second;
        //cout<<temp->data;
        q.pop();

        if(topnode.find(distance) == topnode.end())
            topnode[distance] = temp->data;
        
        if(temp->left)
            q.push(make_pair(temp->left, distance-1));
         
        if(temp->right)
            q.push(make_pair(temp->right, distance+1));
        
    }

    for(auto i: topnode){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}


int main(){
    Node* root = buildTree();

    topView(root);

    return 0;
}