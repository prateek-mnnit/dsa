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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = NULL;
        int sum = 0;
        int tempvalue = 0;
        int carry = 0;

        while(temp1 != NULL && temp2 != NULL){
            sum = temp1->val + temp2->val + carry;
            tempvalue = sum % 10;
            carry = sum/10;

            // dummy->next = new ListNode(tempvalue);
            temp1->val = tempvalue;
            prev = temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;

        }
        if(temp1 == NULL && temp2 == NULL){
            if(carry==0){
                return l1;
            }
            else{
                prev->next = new ListNode(1);
            }
        }
        if(temp1 == NULL){
            if(carry==0){
                prev->next = temp2;
            }
            else{
                while(temp2 !=NULL){
                    sum = temp2->val+ carry ;
                    tempvalue = sum%10;
                    carry = sum/10;
                    prev->next = new ListNode(tempvalue);
                    prev = prev->next;
                    temp2 = temp2->next;
                }

            }
        }
        if(temp2 == NULL){
            if(carry==0){
                prev->next = temp1;
            }
            else{
                while(temp1 !=NULL){
                    sum = temp1->val+ carry ;
                    tempvalue = sum%10;
                    carry = sum/10;
                    prev->next = new ListNode(tempvalue);
                    prev = prev->next;
                    temp1 = temp1->next;
                }

            }
        }
        if(carry==0){
                return l1;
            }
            else{
                prev->next = new ListNode(1);
            }
        return l1;
    }
};