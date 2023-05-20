#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(){
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node(){
        cout<<"node deleted "<<this->data;
        cout<<endl;
    }
};



//to find length of a doubly ll
int findlength(node* head){
    int length = 0;
    node* temp = head;

    while(temp!= NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

//to print a linked list
void printll(node* &head, node* &tail){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    return;
}


//to insert a node in the beginning
void insertatbeg(node* &head, node* &tail, int data){
    node* newnode = new node(data);
 
    if(head == NULL){
        head = tail= newnode;
        return;
    }
    else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }

}

//to insert a node in the end
void insertatend(node* &head, node* &tail, int data){
    
    node* newnode = new node(data);
    if(head ==NULL){
        head = tail = newnode;
        return;
    }
    else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
        return;
    }
}

//to insert at any specified position
void insertatpos(node* &head, node* &tail, int data, int pos){
    if(pos == 0){
        insertatbeg(head, tail, data);
        return;
    }
    if(pos == findlength(head)-1){
        insertatend(head, tail, data);
        return;
    }
    else {
        node* temp= head;
        int count =0;
        while(count<= pos){
            if(count == pos-1){
                break;
            }
            temp = temp->next;
            count ++;
        }
        node* newnode = new node(data);
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        return;
        
    }
}


//to delete a doubly ll from beginning 
void deletefrombeg(node* &head, node* &tail){
    if(head ==NULL){
        return;
    }
    else if(head == tail){
        node* temp = head;
        head = tail = NULL;
        delete temp;
        return;
    }

    else{
        node * temp = head;
        head= head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }
}

//delete a node from the end
void deletefromend(node* &head, node* &tail){
    if(head == NULL){
        return;
    }
    if(head == tail){
        node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    else {
        node* temp = tail;
        tail= tail->prev;
        temp->prev = NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
}

void deletefrompos(node* &head, node* &tail, int pos){
    if(pos ==0){
        deletefrombeg(head, tail);
        return;
    }
    if(pos== findlength(head)-1){
        deletefromend(head, tail);
        return;
    }
    if(pos>findlength(head)-1){
        return;
    }

    else{
        int count =0;
        node* temp = head;
        while(count<= pos){
            if(count == pos){
                break;
            }
            temp = temp->next;
            count++;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->prev = temp->next = NULL;
        delete temp;
        return;
    }
}

int main(){
    node* first = new node(30);
    node* head = first;
    node* tail = first;

    insertatbeg(head, tail, 20);
    insertatbeg(head, tail, 10);
    insertatbeg(head, tail, 0);
    insertatend(head, tail, 40);
    insertatend(head, tail, 50);
    insertatend(head, tail, 60);
    insertatpos(head, tail, 5, 1);
    printll(head, tail);


    cout<<endl;


    deletefrombeg(head, tail);
    deletefromend(head, tail);
    deletefrompos(head, tail, 8);
    printll(head, tail);


}