/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

class Solution {
public:
    ListNode* findtail(ListNode* tail){
        while(tail->next!=NULL){
            tail=tail->next;
        }
        return tail;
    }
    void findnewtail(ListNode* head, ListNode* &temp, int &pos){
        if(head == NULL){
            return;
        }
        findnewtail(head->next, temp, pos);
        
        if(pos == 0){
            temp = head;
        }
        pos--;
    }
    int getLength(ListNode* head){
        int length=0;
        while(head){
            length ++;
            head = head->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        if(k==0 || k%getLength(head) == 0){
            return head;
        }
        k = k%getLength(head);
        ListNode* newTail = head;
        findnewtail(head, newTail, k);
        ListNode* newHead = newTail->next;
        ListNode* tail = findtail(head);
        tail->next = head;
        newTail->next = NULL;
        return newHead;
    }
};