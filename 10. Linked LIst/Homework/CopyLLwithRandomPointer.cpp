/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

//Approach1: map, store all the old and new nodes in a map so it is easier to access consequetive new node via old node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* newHead = new Node(head->val);
        Node* temp = head->next;
        Node* temp1 = newHead;
        unordered_map<Node*, Node*> m;
        m[head] = newHead;

        while(temp != NULL){
            Node* curr = new Node(temp->val);
            temp1->next = curr;
            temp1 = temp1->next;
            m[temp] = temp1;
            temp = temp->next;
        }
        temp1->next = NULL;
        temp = head;
        temp1 = newHead;
        Node* randomptr = temp->random;
        //cout<<temp->random->val<<m[randomptr]->val;
        while(temp != NULL){
            randomptr = temp->random;
            temp1->random = m[randomptr];
            temp = temp->next;
            temp1 = temp1->next;
        }
        
        return newHead;



    }
};




//Approach2: modifying the original LL to make a chain like old->new->old->new. Then make connections to random pointers to new node via old node and then detach the old and the new node
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void printll(Node* head){
        while(head!= NULL){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        
        Node* temp = head;
        Node* curr = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            curr = temp;
            temp = temp->next;
            curr->next = newNode;
            newNode->next = temp;
        }
        printll(head);
        temp = head;
        while(temp){
            if(temp->random == NULL){
                temp = temp->next->next;
                continue;
            }
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        temp = head;
        Node* prev = head;
        temp = temp->next;
        Node* newHead = temp;
        while(temp){
            prev->next = temp->next;
            if(temp->next)
                temp->next = temp->next->next;
            prev = prev->next;
            temp=temp->next;
        }
        return newHead;


    }
};