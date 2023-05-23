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

//function to find the middle node of given linked list
node* middleofLL(node* &head){
 
    node* slow = head;
    node* fast = head->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!= NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    cout<<slow->data;
    return slow->next;                                        //to return the next node of middle since we have to reverse from the next of middle node

}


//function to reverse the linked list from middle node
node* reversefrommiddle(node* &head){
 
    node* prev = NULL;
    node* curr = middleofLL(head);
    node* forward;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    node* middle = middleofLL(head);
    middle->next = prev;
    cout<<middle->data<<endl;

    printll(head);
    return prev;
}

//function to check whether the given LL is a pallindrome or not
bool checkpallindrome(node* &head){

    if(head == NULL){
        return false;
    }

    if(head->next == NULL){
        return true;
    }

    node* temp1 = head;
    node* temp2 = reversefrommiddle(head);

    while(temp2!=NULL){
        if(temp1->data!= temp2->data){
            return false;
        }
        else{
            temp2= temp2->next;
            temp1= temp1->next;
        }
    }
    return true;

}


int main(){
    node* first = new node(1);
    node* head = first;
    
    insertatbeg(head, 2);
    insertatbeg(head, 3);
    insertatbeg(head, 3);
    insertatbeg(head, 2);
    insertatbeg(head, 1);

    printll(head);

    cout<<endl<<checkpallindrome(head);
}