/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

//recursive func to access LL from end to start and use stack to push next greater elements to ans vector
void solve(ListNode* head, stack<int> &s, vector<int> &ans){
        if(head==NULL){
            return;
        }

        solve(head->next, s, ans);

        

        if(s.empty()){
            ans.push_back(0);
        }
        else if(s.top() > head->val){
            ans.push_back(s.top());
        }
        else{
            while(s.empty()==0 && s.top()<= head->val){
                s.pop();
            }
            if(!s.empty())
            ans.push_back(s.top());
            else{
                ans.push_back(0);
            }
        }   
            s.push(head->val);
            return;

    }
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> s;
        vector<int> ans;

        if(head->next == NULL){
        ans.push_back(0);
            return ans;
        }

        solve(head, s, ans);
        
        reverse(ans.begin(), ans.end());
    
        
        return ans;
    }
};