#include <iostream>
#include <vector>
using namespace std;

// class to create a node with default and parameterized constructors
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
    cout << endl;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

// function to find the critical points in a LL
void findcriticalpoints(node *&head, vector<int> &arr)
{
    node *temp = head;
    int i = 2;
    while (temp->next->next)
    {
        if (temp->next->data > temp->data && temp->next->data > temp->next->next->data)
        {
            arr.push_back(i);
        }
        else if (temp->next->data < temp->data && temp->next->data < temp->next->next->data)
        {
            arr.push_back(i);
        }
        temp = temp->next;
        i++;
    }

    return;
}

// function to find minimum and maximum distance between ciritcal nodes
void findminmax(vector<int> &ans, vector<int> &arr)
{
    int maxi = 0, mini = 100000;
    maxi = abs(arr[arr.size() - 1] - arr[0]);
    for (int i = 0; i < arr.size() - 1; i++)
    {
        mini = min(mini, abs(arr[i] - arr[i + 1]));
    }
    ans.push_back(mini);
    ans.push_back(maxi);
}

vector<int> nodesBetweenCriticalPoints(node *head)
{
    vector<int> ans;
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    vector<int> arr;
    findcriticalpoints(head, arr);

    if (arr.size() < 2)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    findminmax(ans, arr);

    return ans;
}
// main function
int main()
{
    // creating LL 1
    node *head = new node(2);
    insertatbeg(head, 1);
    insertatbeg(head, 5);
    insertatbeg(head, 2);
    insertatbeg(head, 1);
    insertatbeg(head, 3);
    insertatbeg(head, 5);
    vector<int> ans;
    printll(head);
    ans = nodesBetweenCriticalPoints(head);
    cout<<endl<<ans[0]<<"\t"<<ans[1];

    return 0;
}
