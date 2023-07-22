/*
 You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);                        //-1 is a dummy node for us to attach further nodes 
        ListNode* tail = head;
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;

        for(int i=0; i< lists.size(); i++){
            if(lists[i] != NULL){
                ListNode* temp = lists[i];
                heap.push(temp);
            lists[i]= lists[i]->next;
            }
        }        

        while(!heap.empty()){
            ListNode* temp = heap.top();
            tail->next = temp;
            tail = temp;
            heap.pop();

            if(temp->next != NULL){                                    //we do not need to track the toprow since we can access the next eleemnt of top via next pointer of LL unlike in
                ListNode* newnode = temp->next;
                heap.push(newnode);
            }
        }
        return head->next;
    }
