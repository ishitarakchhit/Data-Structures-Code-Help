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

// to delete a node from beginning
void deletefrombeg(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return;
}

// to delete from the end
void deletefromend(node *&head, node *&tail)
{
    if (tail == NULL)
    {
        return;
    }
    if (tail == head)
    {
        node *temp = tail;
        tail = NULL;
        head = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
    temp = temp->next;
    delete temp;
}

// to delete from a specified position
void deletefrompos(node *&head, node *&tail, int pos)
{
    if (pos == 0)
    {
        deletefrombeg(head);
        return;
    }
    else if (pos == (findlength(head) - 1))
    {
        deletefromend(head, tail);
        return;
    }

    else
    {
        node *temp = head;
        int count = 0;
        while (count <= pos)
        {
            if (count == pos-1)
            {
                break;
            }
            temp = temp->next;
            count++;
        }
        node *prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
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

    deletefrombeg(head);
    deletefromend(head, tail);
    deletefrompos(head, tail, 1);
    deletevalue(head, tail, 30);
    cout << endl;
    printll(head);
}