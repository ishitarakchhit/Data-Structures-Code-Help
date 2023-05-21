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

//function to find length of a linked list
int findlength(node* &head){
    node* temp = head;
    int length=0;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

//function to reverse a linked list in groups of k using recursion
node* reverseinkgroups(node* &head, int k){
    if(head == NULL){
        cout<<"LL is empty";
        return head;
    }
    if(k> findlength(head)){
        cout<<"Enter valid value of k";
        return head;
    }
    node* curr = head;
    node* prev=NULL;
    node* forward = curr->next;
    int count=0;
    while(count<k){
        forward= curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++; 
    }
    if(forward!= NULL){
    head->next = reverseinkgroups(forward, k);                   //to join the current group to next group 

    }

    return prev;                                                 //this returns the head of the complete list
}



int main(){
    node* first = new node(10);
    node* head = first;
    
    insertatbeg(head, 9);
    insertatbeg(head, 8);
    insertatbeg(head, 7);
    insertatbeg(head, 6);
    insertatbeg(head, 5);
    printll(head);

    head = reverseinkgroups(head, 6);
    cout<<endl;
    printll(head);
    
}