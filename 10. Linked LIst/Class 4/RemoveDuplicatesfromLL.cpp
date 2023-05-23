#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//to insert at beginning
void insertatbeg(node* &head, int data){
    node* newnode = new node(data);

    newnode->next = head;
    head = newnode;
    return;

}

//to print a linked list
void printll(node* &head){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}


//main function
int main(){
    node* first = new node(4);
    node* head = first;
    
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 3);
    insertatbeg(head, 3);
    insertatbeg(head, 2);
    insertatbeg(head, 2);
    insertatbeg(head, 2);
    insertatbeg(head, 1);

    printll(head);

   
 
}