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
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* curr2 = curr;
        ListNode* temp = NULL;

        while (curr != tail) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        curr2->next = tail;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* temp2 = head;
        ListNode* prevTail = NULL;

        int count = 1;

        while (temp2 != NULL) {

            if (count % k == 0) {

                ListNode* nextGroup = temp2->next;

                ListNode* newHead = reverseList(temp, nextGroup);

                if (prevTail == NULL) {
                    head = newHead;      // first reversed group
                } else {
                    prevTail->next = newHead;
                }

                prevTail = temp;         // old head becomes tail

                temp = nextGroup;
                temp2 = nextGroup;
            }
            else {
                temp2 = temp2->next;
            }

            count++;
        }

        return head;
    }
};