#include<iostream>
using namespace std;


//class to create a node with default and parameterized constructors 
class Node{
    public:
    int val;
    Node* next;

    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

//to insert at beginning
void insertatbeg(Node* &head, int data){
    Node* newnode = new Node(data);

    newnode->next = head;
    head = newnode;
    return;

}

//to print a linked list
void printll(Node* &head){
    cout<<endl;
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    return;
}

void linkdelete(Node  *&head, int M, int N)
    {   if(!head)
            return;
        Node* temp = head;
        Node* curr = head;
        int m = M-1, n = N;
        while(temp!=NULL){
            
            if(!m){
                while(n){
                    curr = temp->next;
                    if(curr){
                        temp->next = curr->next;
                        curr->next = NULL;
                        delete curr;
                    }
                        n--;
                }
                m = M;
            n = N;
            }
            m--;
            temp = temp->next;
            printll(head);
        }
        //Add code here   
        cout<<"e";
        return ;
    }


//main function
int main(){
    //creating LL 1
    Node* head = new Node(-10);
    insertatbeg(head, -9);
    

    printll(head);


    linkdelete(head, 3, 2);

    printll(head);

    return 0;
}

