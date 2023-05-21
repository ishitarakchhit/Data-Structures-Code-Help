#include<iostream>
using namespace std;

//class to create a node, having a default and parameterized constructor
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


//to insert a node at beginning of a linked list
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


//to find whether a loop is present of not using floyyed cycle detection algorithm
bool islooppresent(node* &head){
    node* slow = head;
    node* fast = head;
    
    if(head == NULL){
        cout<<"LL is empty";
        return false;
    }

    while(slow!=NULL && fast !=NULL){
        fast=fast->next;
        
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow == fast){
            return true;
        }
    }

    return false;
}

//to find the starting point of a loop which is already present in a linked list
node* findstart(node* &head){
    if(head == NULL){
        return NULL;
    }

    node* slow = head;
    node* fast = head;

    while(fast != NULL){                           //loop to find the intersection of slow and fast pointers
        fast = fast->next;
        
        if(fast!=NULL){
            fast=fast->next;
            slow = slow->next;
        }
        
        if(slow == fast){                          //condition to point slow to the head pointer again
            slow= head;
            break;
        }
    }

    while(slow!=fast){                              //loop to increment slow and fast pointers by 1 so that they meet at the starting point of loop
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}


//function to remove the loop
void removeloop(node* &head){
    if(head == NULL){
        return ;
    }

    node* slow = head;
    node* fast = head;
    
    while(fast != NULL){                           //loop to find the intersection of slow and fast pointers
        fast = fast->next;

        if(fast!=NULL){
            fast=fast->next;
            slow = slow->next;
        }

        if(slow == fast){                          //condition to point slow to the head pointer again
            slow= head;
            break;
        }
    }
    
    node* prev = fast;

    while(slow!=fast){                              //loop to increment slow and fast pointers by 1 so that they meet at the starting point of loop
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    prev->next = NULL;

    return;

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
    insertatbeg(head, 4);
    insertatbeg(head, 3);
    insertatbeg(head, 2);
    insertatbeg(head, 1);
    tail->next = head->next->next->next->next;
    

    cout<<islooppresent(head);
    
    node* startloop = findstart(head);
    cout<<endl<<"Start of loop contains data: "<<startloop->data<<endl;
    
    removeloop(head);
    
    printll(head);
    

    return 0;
}