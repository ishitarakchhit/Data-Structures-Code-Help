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
    cout<<endl;
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return;
}



//function to find middle of LL
node* findMiddle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
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


//function to implement merge sort
node* mergesort(node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }

    node* mid = findMiddle(head);
    node* left = head;
    
    node* right = mid->next;
    mid->next = NULL;

    //RC
    left = mergesort(left);

    right = mergesort(right);            //RC
    
    node* merged = mergeLL(left, right);           //To merge two LLs

    return merged;

}




//main function
int main(){
    //creating LL 1
    node* head = new node(-10);
    insertatbeg(head, -9);
    insertatbeg(head, -8);
    insertatbeg(head, -7);
    insertatbeg(head, -6);
    insertatbeg(head, 3);
    insertatbeg(head, 4);
    insertatbeg(head, 5);

    printll(head);


    // while(e->next != NULL){
    //     e = e->next;
    // }

    head = mergesort(head);
    printll(head);

    return 0;
}

