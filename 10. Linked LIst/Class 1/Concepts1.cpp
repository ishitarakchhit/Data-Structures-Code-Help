#include<iostream>
using namespace std;


//to create a node
class Node{
    public:
        int data;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        // ~Node(int data){
        //     cout<<"NOde with value: "<<data<<" is deleted";
        // }
};


//function to print the linked list
void printll(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
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



//to insert a node at the first or starting
void insertAtHead(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}


//insert at the end
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}


//to insert a node at a given position
void insertAtPosition(Node* & head, Node* &tail, int data, int position){
    Node* newNode = new Node(data);
    Node* temp = head;

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    if(position==0){
        insertAtHead(head, tail, data);
        return;
    }

    int length = findLength(head);
    if(position == length){
        insertAtTail(head, tail, data);
        return;
    }

    int i=1;
    while(i<position){
        temp = temp->next;
        i++;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}




//to delete a node from LL
void deleteNode(Node* head, Node* tail, int Position){
    if(head == NULL){
        cout<<"LL is empty";
        return;
    }

    if(Position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int length = findLength(head);
    if(Position == length){
        int i=1;
        Node* prev = head;
        while(i< Position-1){
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node* temp = tail;
        delete temp;
        return;
    }

    int i=1;
    Node* prev = head;
    while(i<Position-1){
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;
    prev->next = curr->next;
    delete curr;
}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);

    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 80);
    insertAtTail(head, tail, 90);

    insertAtPosition(head, tail, 101, 3);
    insertAtPosition(head, tail, 101, 0);
    insertAtPosition(head, tail, 101, 8);

    deleteNode(head, tail, 1);
    

    printll(head);
}