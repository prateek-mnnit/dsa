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
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        int half = count/2 +1;
        if(count == 1 || count == 0){
            return NULL;
        }

        int i = 1;
        temp = head;
        while(i<half-1){
            i++;
            temp = temp->next;
        }
        ListNode* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return head;
    }
};