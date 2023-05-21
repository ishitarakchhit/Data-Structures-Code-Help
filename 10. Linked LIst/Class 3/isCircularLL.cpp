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



//function to check whether the linked list is circular or not
//Approach1: 1 pointer approach, slow fast approach, map approach 
bool iscircularLL(node* &head){
    node* temp = head->next;

    while(temp!=NULL){
        if(temp == head){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


//main function
int main(){
    node* first = new node(10);
    node* head = first;
    node* tail = first;
    
    insertatbeg(head, 9);
    insertatbeg(head, 8);
    insertatbeg(head, 7);
    insertatbeg(head, 6);
    insertatbeg(head, 5);
    tail->next = head;

    cout<<iscircularLL(head);
    
}