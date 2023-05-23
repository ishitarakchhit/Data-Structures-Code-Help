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


//function to remove duplicates from linked list
void removeduplicates(node* &head){

    if(head== NULL || head->next==NULL){
        return;
    }
    node* curr = head;
    while(curr!=NULL){
        if(curr->next == NULL){
            break;
        }

        if(curr->data == curr->next->data){           //if elements are repeating then delete the repeating element and coneect the previous node to the next node
            node* temp = curr->next;
            curr->next = curr->next->next;
            temp->next =NULL;
            delete temp;
        }

        else{                                         //if elements are not repeating iterate over the next node
            curr = curr->next;
        }
    }
    return;
}

//main function
int main(){
    node* head = new node(4);
    
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 3);
    insertatbeg(head, 3);
    insertatbeg(head, 3);
    insertatbeg(head, 2);
    insertatbeg(head, 2);
    insertatbeg(head, 2);
    insertatbeg(head, 1);

    printll(head);

    cout<<endl;

    removeduplicates(head);                             //function call to remove duplicates from linked list
    printll(head);

   
 
}