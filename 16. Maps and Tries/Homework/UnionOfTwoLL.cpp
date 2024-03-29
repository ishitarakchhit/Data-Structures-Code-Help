/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 
1 2 3 4 6 8 9
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output. 
Example 2:

Input:
L1 = 1->5->1->2->2->5
L2 = 4->5->6->7->1
Output: 
1 2 4 5 6 7
Explaination: 
All the distinct numbers from two lists, when sorted forms the list in the output.
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Expected Time Complexity: O((N+M)*Log(N+M))
Expected Auxiliary Space: O(N+M)

Constraints:
1<=N,M<=104
*/


struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        map<int, Node*> m;

        //mapping all elements of head1 to map 
        while(head1){
            m[head1->data] = head1;
            head1=head1->next;
        }
        //mapping all elements of head2 to map 
        while(head2){
            m[head2->data] = head2;
            head2 = head2->next;
        }
        Node* dummy = new Node(-1);
        Node* head = dummy;

        //loop to create answer LL
        for(auto i = m.begin(); i!=m.end(); i++){
            dummy->next = i->second;
            dummy=dummy->next;
        }
        dummy->next = NULL;                       //mistake-----! forgot to add this
        
        return head->next;
    }