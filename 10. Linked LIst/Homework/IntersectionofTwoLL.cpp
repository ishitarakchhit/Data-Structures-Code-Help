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

//function to return the intersection of LL
//Approach1: first we find the difference in length of both LLs. Then travel the bigger LL by their length difference. Then both are traversed at the same time and whenever node becomes equal the function returns it
node* intersection(node* head1, node* head2){
    if(head1->next == NULL && head2->next == NULL && head1!=head2){
        return NULL;
    }

    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int travel = abs(len1 - len2);
    
    if(len1 > len2){
        while(travel){
            head1 = head1->next;
            travel--;
        }
    }

    else if(len1 < len2){
        while(travel){
            head2 = head2->next;
            travel--;
        }
    }

    while(head1!=head2){
            head1 = head1->next;
            head2 = head2->next;
    }
    return head1;


}



//main function
int main(){
    //creating LL 1
    node* head1 = new node(10);
    insertatbeg(head1, 9);
    insertatbeg(head1, 8);
    insertatbeg(head1, 7);
    insertatbeg(head1, 6);
    insertatbeg(head1, -5);
    insertatbeg(head1, -4);
    insertatbeg(head1, -3);

    //creating LL2
    node* head2 = new node(10);
    insertatbeg(head2, 9);
    insertatbeg(head2, 8);
    insertatbeg(head2, 7);
    insertatbeg(head2, 6);
    insertatbeg(head2, 5);
    insertatbeg(head2, 4);

    printll(head1);
    cout<<endl;
    printll(head2);
    cout<<endl;

    node* intersect = intersection(head1, head2);
    cout<<"Intersection node is: "<<intersect->data;
    return 0;
}