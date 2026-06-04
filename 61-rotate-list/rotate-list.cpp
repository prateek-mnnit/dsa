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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int count = 0;
        if(head == NULL || head->next == NULL){
            return head;
        }
        while(temp != NULL){
            count++;
            prev = temp;
            temp = temp->next;
        } 
        k = k % count;
        int pos = count-k;
        temp = head;
        int i = 1;
        while(i<pos){
            temp = temp->next;
            i++;
        }
        prev->next =head;
        head = temp->next;
        temp->next = NULL;

        return head;

    }
};