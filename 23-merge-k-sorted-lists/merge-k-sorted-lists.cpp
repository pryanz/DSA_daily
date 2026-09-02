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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; i++){
            ListNode * temp = lists[i];
            while(temp){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        while(!pq.empty()){
            ListNode * node = new ListNode(pq.top());
            pq.pop();

            if(!head){
                head = node;
                tail = node;
            } else{
                tail->next = node;
                tail = tail->next;
            }
        }

        return head;
    }
};