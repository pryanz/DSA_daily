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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* delNode = nullptr;
        ListNode* temp = head;
        int diff = n - 1;
        while(temp && diff){
            temp = temp->next;
            diff--;
        }
        delNode = head;
        ListNode * prev = nullptr;
        while(temp->next){
            temp = temp->next;
            prev = delNode;
            delNode = delNode->next;
        }
        if(delNode == head) return head->next;
        prev->next = delNode->next;
        return head;
    }
};