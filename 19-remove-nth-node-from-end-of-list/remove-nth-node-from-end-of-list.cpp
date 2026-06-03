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
        ListNode* temp = head;
        if (head == NULL) {
            return NULL;
        }
        if(head->next == NULL && n==1){
            return NULL;
        }

        int count = 1;

        while (temp->next != NULL) {
            count++;
            temp = temp->next;
        }
        int pos = count - n + 1;

        int i = 1;
        temp = head;
        while (i < pos-1) {
            i++;
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;

        if(n == count && temp == head){
            temp = temp->next;
            delete head;
            return temp;
        }
        if (temp->next != NULL) {
            temp->next = temp->next->next;
        } else {
            temp->next = NULL;
        }
        delete temp2;

        return head;
    }
};