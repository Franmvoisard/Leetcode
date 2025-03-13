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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr; //Edge case
        ListNode* hare = head->next;
        ListNode* tortoise = head;

        while(hare->next != nullptr && hare->next->next != nullptr){
            hare = hare->next->next;
            tortoise = tortoise->next;
        }

        tortoise->next = tortoise->next->next;
        return head;
    }
};
