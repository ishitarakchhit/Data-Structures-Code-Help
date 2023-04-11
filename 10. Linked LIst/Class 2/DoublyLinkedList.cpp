#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

//function to print the linked list
void printLL(Node* &head, Node* &tail){
    Node* temp = head;

    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }

}


//to find the length of a linked list
int findLength(Node* &head){
    int length=0;
    Node* temp = head;

    while(temp!= NULL){
        length++;
        temp = temp-> next;
    }
    return length;
}


//to insert the node at head
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = head;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


//to insert the node at tail
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;

}


//to insert at any position
// void insertAtPosition(Node* &head, Node* &tail, int data, int position){
//     if(head == NULL){
//         Node* newNode = new Node(data);
//         head = newNode;
//         tail = newNode;
//         return;
//     }

//     else{
//         if(position==1){
//             insertAtHead(head, tail, data);
//             return;
//         }
//         int length = findLength(head);

//         else if(position>length){
//             insertAtTail(head, tail, data);
//             return;
//         }
//         else {
//             int i=1;
//             Node* newNode = new Node(data);
//             Node* prevNode = head;
//             while(i<position-1){
//                 prevNode= prevNode ->next;
//                 i++;
//             }
//             prevNode->next->prev = newNode;
//             newNode->next = prevNode->next;
//             prevNode->next = newNode;
//             newNode->prev = prevNode;
//         }
//     }
// }


//to insert a node in doubly linked list 
int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* head = first;

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    Node* tail = third;

    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 7);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    printLL(head, tail);
}