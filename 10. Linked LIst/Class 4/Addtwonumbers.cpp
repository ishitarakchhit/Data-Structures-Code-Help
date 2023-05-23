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


//function to reverse a linked list using recursion
node* reverseLL(node* &prev, node* &curr){
    if(curr == NULL){
        return prev;
    }

    node* forward = curr->next;
    curr->next= prev;
    return reverseLL(curr, forward);
}


//function to add two numbers which are represented in a linked list
node* addnumbers(node* head1, node* head2){

    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    //function calls to reverse the linked list
    node* prev = NULL;
    head1 = reverseLL(prev, head1);
    head2 = reverseLL(prev, head2);

    //creating all variables to iterate over LLs, and creating a new LL which represents dummy node to new LL or anwer LL
    node* temp1 = head1;
    node* temp2 = head2;
    node* temp = new node(-101);
    node* head = temp;
    int ans = 0, carry =0;

    //loop to iterate over LLs and add data with carry and store single digit to new node and attach it to final answer node
    while(temp1 != NULL && temp2 != NULL){
        ans = temp1->data + temp2->data + carry;
        carry = ans/10;
        ans = ans%10;

        node* curr = new node(ans);
        temp->next = curr;
        temp = temp->next;
        temp1= temp1->next;
        temp2= temp2->next;

    }

    //loop to iterate over remaining 1st LL
    while(temp1 != NULL ){
        ans = temp1->data + carry;
        carry = ans/10;
        ans = ans%10;

        node* curr = new node(ans);
        temp->next = curr;
        temp = temp->next;
        temp1= temp1->next;
    }

    //loop to iterate over remaining 2nd LL
    while( temp2 != NULL){
        ans =  temp2->data + carry;
        carry = ans/10;
        ans = ans%10;

        node* curr = new node(ans);
        temp->next = curr;
        temp = temp->next;
        temp2= temp2->next;
    }

    //loop to store remaining carry to LL
    while(carry!=0){
        int ans = carry;
        carry = ans/10;
        ans = ans%10;

        node* curr = new node(ans);
        temp->next = curr;
        temp = temp->next;
    }

    //to delete the dummy node from answer LL
    temp = head;
    head = head->next;
    delete temp;

    //function call to reverse LL and return the head
    head = reverseLL(prev, head);

    return head;
}


//main function
int main(){
    node* head1 = new node(9);
    insertatbeg(head1, 9);
    insertatbeg(head1, 9);
    insertatbeg(head1, 9);
    insertatbeg(head1, 9);

    node* head2 = new node(9);
    insertatbeg(head2, 9);
    insertatbeg(head2, 9);
    insertatbeg(head2, 9);

    printll(head1);
    cout<<endl;
    printll(head2);

    cout<<endl;
    node* head = addnumbers(head1, head2);
    printll(head);
    return 0;
}