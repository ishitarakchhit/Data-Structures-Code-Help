/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.
For more clarity have a look at the printList() function in the driver code.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
*/

Node *merge(Node* &left, Node* &right){
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    
    Node* temp1 = left;
    Node* temp2 = right;
    Node* head = new Node(-101);
    Node* temp = head;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            temp->bottom = temp1;
            temp = temp->bottom;
            temp1 = temp1->bottom;
        }
        else if(temp1->data > temp2->data){
            temp->bottom = temp2;
            temp = temp->bottom;
            temp2 = temp2->bottom;
        }
        else{
            temp->bottom = temp1;
            temp = temp->bottom;
            temp1 = temp1->bottom;

            temp->bottom = temp2;
            temp2 = temp2->bottom;
            temp = temp->bottom;
        }
    }

    if(temp1 != NULL){
        temp->bottom = temp1;
        temp = temp->bottom;
    }
    if(temp2 != NULL){
        temp->bottom = temp2;
        temp = temp->bottom;
    }

    
    return head->bottom;
}
    
    



    
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    //below code takes out the first LL and names it as head and root now points to root->next 
    Node* temp = root;
    Node* head = new Node(-101);
    head->bottom = root;
    root = root->next;
    Node* dummy = head;
    head = head->bottom;
    delete dummy;
    head->next = NULL;
    temp = root;
    
    //we now traverse main LL and keep merging head and consecutive LLs at every iteration
    while( temp != NULL){
        head = merge(head, temp);
        temp = temp->next;
    }
    
    return head;
    
   // Your code here
}