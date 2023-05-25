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


//function to return the length of LL
int getLength(node* &head){
    node* temp = head;
    int length =0;
    while(temp != NULL){
        length ++;
        temp = temp->next;
    }
    return length;
}


//function to merge two sorted Linnked List.
//Approach: Two pointer
node* mergeLL(node* head1, node* head2){
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }

    node* temp1 = head1;
    node* temp2 = head2;
    node* head = new node(-101);
    node* temp = head;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
        }
        else if(temp1->data > temp2->data){
            temp->next = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        else{
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;

            temp->next = temp2;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }

    if(temp1 != NULL){
        temp->next = temp1;
        temp = temp->next;
    }
    if(temp2 != NULL){
        temp->next = temp2;
        temp = temp->next;
    }

    
    return head->next;
}



//main function
int main(){
    //creating LL 1
    node* head1 = new node(10);
    insertatbeg(head1, 9);
    insertatbeg(head1, 8);
    insertatbeg(head1, 7);
    insertatbeg(head1, 6);
    insertatbeg(head1, -3);
    insertatbeg(head1, -4);
    insertatbeg(head1, -5);

    //creating LL2
    node* head2 = new node(9);
    insertatbeg(head2, 8);
    insertatbeg(head2, 7);
    insertatbeg(head2, 6);
    insertatbeg(head2, 5);
    insertatbeg(head2, 4);

    printll(head1);
    cout<<endl;
    printll(head2);
    cout<<endl;

    node* head = mergeLL(head1, head2);
    cout<<"Merged LL is: ";
    printll(head);
    return 0;
}