#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

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

// function to sort the linkedlist
// Approach1: count all thw 0s 1s and 2s, then iterate over the LL and copy all the 012 accoding to their frequency
// Approach2: initialize three dummy nodes with values -1, these nodes will point to 012 seperately. Then finally join these nodes and delete the value -1 from each one
node *sort012(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *head0 = new node(-1);
    node *head1 = new node(-1);
    node *head2 = new node(-1);
    node *temp0 = head0;
    node *temp1 = head1;
    node *temp2 = head2;
    node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            temp0->next = curr;
            temp0 = curr;
            curr = curr->next;
            temp0->next = NULL;
        }
        else if (curr->data == 1)
        {
            temp1->next = curr;
            temp1 = curr;
            curr = curr->next;
            temp1->next = NULL;
        }
        else
        {
            temp2->next = curr;
            temp2 = curr;
            curr = curr->next;
            temp2->next = NULL;
        }
    }


    node* temp = head1;
    head1 = head1->next;
    temp->next = NULL;
    delete temp;

    temp = head2;
    head2 = head2->next;
    temp->next = NULL;
    delete temp;

    if(head1!= NULL){
        temp0->next = head1;
        if(head2!= NULL){
            temp1->next = head2;
        }
    }

    else if(head2 != NULL){
        temp0->next = head2;
    }

    temp = head0;
    head0 = head0->next;
    temp->next = NULL;
    delete temp;

    return head0;
}

// main function
int main()
{
    node *head = new node(1);

    insertatbeg(head, 1);
    insertatbeg(head, 1);
    insertatbeg(head, 1);
    insertatbeg(head, 1);
    insertatbeg(head, 1);
    insertatbeg(head, 1);

    printll(head);

    head = sort012(head);
    cout << endl;
    printll(head);
}