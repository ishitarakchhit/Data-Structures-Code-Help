#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//class to create a node
class node
{
public:
    int data;
    node *next;

    node()
    {
        this->data = 0;
        this->next = NULL;
    }
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// to insert at beginning
void insertatbeg(node *&head, int data)
{
    node *newnode = new node(data);

    newnode->next = head;
    head = newnode;
    return;
}

// to print a linked list
void printll(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}


//function to find the kth node from end in a linked list
//Approach1: Using recursion
//Approach2: Using iterative method, find the total length of LL and then return (length-pos)th node from starting
void rec(node* &head, node* &temp, node* &ans, int &count, int pos){
    if(temp == NULL){
        return;
    }
    rec(head, temp->next, ans, count, pos);
    count++;
    if(count == pos){
        ans = temp;
        return;
    }
}


// main function
int main()
{
    node *head = new node(1);

    insertatbeg(head, 2);
    insertatbeg(head, 3);
    insertatbeg(head, 4);
    insertatbeg(head, 5);
    insertatbeg(head, 6);
    insertatbeg(head, 7);

    printll(head);
    node* temp = head;
    node* ans = NULL;
    int count =-1;
    rec(head, temp, ans, count, 5);
    cout << endl;
    cout<<ans->data;
}