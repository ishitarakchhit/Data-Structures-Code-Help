#include<iostream>
using namespace std;


//class to create a node with default and parameterized constructors 
class node{
    public:
    int data;
    node* next;

    node(){
        this->data = 0;
        this->next = NULL;
    }
    node(int val){
        this->data = val;
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
    cout<<endl;
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}


//function to merge nodes between zeroes
node* mergenodes(node* &head){
    
    node* temp = head;
    node* forward = head;
    while(temp){
        if(temp->data == 0){
            temp = temp->next;
        }
        else{
            forward = temp->next;
            if(forward->data == 0){
                temp = temp->next;
            }
            else{
                temp->data = temp->data + forward->data;
                temp->next = forward->next;
                forward->next = NULL;
                delete forward;
            }
        }
    }

    temp = head;
    head = head->next;
    delete temp;
    temp = head;
    
    while(temp){
        forward = temp->next;
        temp->next = forward->next;
        forward->next = NULL;
        delete forward;
        temp = temp->next;

    }
    return head;
}


//main function
int main(){
    //creating LL 1
    node* head = new node(0);
    insertatbeg(head, 2);
    insertatbeg(head, 5);
    insertatbeg(head, 4);
    insertatbeg(head, 0);
    insertatbeg(head, 1);
    insertatbeg(head, 3);
    insertatbeg(head, 0);

    printll(head);

    head = mergenodes(head);

    printll(head);

    return 0;
}

