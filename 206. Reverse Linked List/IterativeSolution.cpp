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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current != nullptr){ //Until there are no more nodes
            next = current->next; //cache the next pointer before breaking the link
            current->next = prev; //next pointer connects to the previous element (point to the head of the new ll)
            prev = current; //set current node as the new head of the reverted ll
            current = next; //current node will be the node we've cached before breaking the link
        }
        return prev;
    }
};
