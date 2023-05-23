#include<iostream>
#include<vector>
#include <unordered_map>
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
//Approach1: using nested loops, start a loop follwed by another, if i->data == j->data then drop jth node and point i->next to j->next
//Approach2: using unordered map
//Approach3: sort the list and follow the procedure when we remove duplicates from sorted LL 
void removeduplicates(node* &head){
    unordered_map<int, bool> m;
    
    node* curr = head;
    node* prev = head;

    while(curr!= NULL){

        if(m[curr->data] == true){
            node* temp = curr;
            prev->next = curr->next;
            curr=curr->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            m[curr->data] = true;
            prev = curr;
            curr=curr->next;
        }
        
    }
    return;
}

//main function
int main(){
    node* head = new node(4);
    
    insertatbeg(head, 3);
    insertatbeg(head, 4);
    insertatbeg(head, 4);
    insertatbeg(head, 2);
    insertatbeg(head, 2);
    insertatbeg(head, 1);

    printll(head);

    cout<<endl<<"back";

    removeduplicates(head);                             //function call to remove duplicates from linked list
    printll(head);

   
 
}