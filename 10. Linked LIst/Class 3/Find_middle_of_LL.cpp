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

int findlength(node* &head){
    node* temp = head;
    int length=0;
    while(temp != NULL){
        temp = temp->next;
        length++;
    }
    return length;
}

//Approach1: to find the length of linked list and then find the node present at n/2th or n/2+1 th position
int findmiddle(node* &head){
    int length = findlength(head);
    if(length%2 == 0){
        length = length/2;
    }
    else {
        length = length/2 +1;
    }

    node* temp = head;
    int count =0;
    while(count <length){
        if(count ==length-1){
            return temp->data;
        }
        temp= temp->next;
        count++;
    }
    return temp->data;
}

// Approach2: find middle of linked list using tortoise approach/2 pointer/slow fast appraoch
//slow is incremented by 1 and fast is increemnted by 2 until fast does not reach the end. slow finally points to middle of linked list
void findmiddle2(node* head){
    if(head ==NULL){
        cout<<"LL is empty";
        return;
    }
    node* s = head;
    node* f= head;

    while(f!= NULL && s!=NULL){
        f=f->next;
        if(f!= NULL && f->next!=NULL){
            f=f->next;
            s=s->next;
        }
    }
    cout<<s->data;
}


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

int main(){
    node* first = new node(10);
    node* head = first;
    
    insertatbeg(head, 9);
    insertatbeg(head, 8);
    insertatbeg(head, 7);
    insertatbeg(head, 6);
    insertatbeg(head, 5);
    printll(head);

    cout<<endl<<findmiddle(head);
    findmiddle2(head);
    
}