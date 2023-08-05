/*
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
*/

Node* findIntersection(Node* head1, Node* head2)
    {
        // code here
        // return the head of intersection list
        unordered_map<int, bool> map;
        
        //hasing list 2 items
        while(head2){
            map[head2->data] = true;
            head2 = head2->next;
        }
        
        Node* head = new Node(-1);
        Node* tail = head;
        
        //checking for items in list 1 and list 2 then attaching it to new ans list
        while(head1){
            if(map[head1->data]){
                tail->next = head1;
                tail = tail->next;
            }
                head1 = head1->next;
        }
        tail->next = NULL;
        return head->next;
    }