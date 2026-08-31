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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        vector<int> crits;
        for(int i = 1; i < nums.size() - 1; i++){
            if((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || (nums[i] < nums[i-1] && nums[i] < nums[i+1])){
                crits.push_back(i);
            }
        }
        if(crits.size() < 2) return {-1,-1};
        int minD = INT_MAX;
        for(int i = 0; i < crits.size() - 1; i++){
            minD = min(minD, abs(crits[i+1] - crits[i]));
        }
        return {minD, crits.back() - crits[0]};
    }
};