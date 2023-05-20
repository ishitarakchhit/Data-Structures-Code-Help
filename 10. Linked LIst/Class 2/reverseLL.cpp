#include <iostream>
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

// to find the length of a ll
int findlength(node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

// to insert a node at the beginning
void insertatbeg(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
    return;
}

// to insert at the end of ll
void insertatend(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);

    if (tail == NULL)
    {
        head = tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

// to insert a node at a specified position
void insertatpos(node *&head, node *&tail, int data, int pos)
{
    if (pos == 0)
    {
        insertatbeg(head, tail, data);
        return;
    }
    if (pos == findlength(head) + 1)
    {
        insertatend(head, tail, data);
        return;
    }
    else
    {
        node *temp = head;
        int count = 0;
        while (count <= pos)
        {
            node *newnode = new node(data);
            if (count == pos - 1)
            {
                newnode->next = temp->next;
                temp->next = newnode;
            }
            temp = temp->next;
            count++;
        }
    }
}

//to reverse a linked list using recursion
node* reversell(node* &prev, node* &curr){
    if(curr == NULL){
        return prev;
    }

    
        node* forward = curr->next;
        curr->next = prev;
        reversell(curr, forward);
    
}

//to reverse a linked list using loop
node* reversellusingloop(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* forward = curr->next;

    while(curr!= NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward; 
    }
    return prev;
}


// to print a linked list
void printll(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// main function
int main()
{
    node *first = new node(10);

    node *head = first;
    node *tail = first;

    insertatbeg(head, tail, 0);
    insertatend(head, tail, 20);
    insertatend(head, tail, 30);
    insertatend(head, tail, 40);
    insertatpos(head, tail, 25, 3);
    printll(head);

    cout<<endl;

    node* prev = NULL;
    node* curr = head;
    head = reversell(prev, curr);
    head = reversellusingloop(head);
    printll(head);
}