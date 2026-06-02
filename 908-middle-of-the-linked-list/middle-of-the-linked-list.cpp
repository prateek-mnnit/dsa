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
    ListNode* middleNode(ListNode* head) {
        int count = 1;
        ListNode* temp = head;
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        while(temp->next != 0){
            count++;
            temp = temp->next;
        }  

        count = count/2 + 1;
        int i = 1;
        temp = head;

        while(i<count){
            temp = temp->next;
            i++;
        }
        return temp;

    }
};