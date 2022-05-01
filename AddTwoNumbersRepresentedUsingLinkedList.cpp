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
        if(l1 == NULL )
            return l2;
        if(l2 == NULL)
            return l1;
        int carry =0 ;
        ListNode *p = new ListNode(0);
        ListNode *NewList = p ;
        while(l1 && l2)
        {
             NewList->next = new ListNode((l1->val + l2->val+carry) %10 );
            carry = (l1->val + l2->val + carry) / 10;
           
            NewList = NewList->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
           // cout<<"raf";
            NewList->next =new ListNode((l1->val + carry)%10 );
            carry = (l1->val + carry )/10;
            l1 = l1->next;
            NewList = NewList->next;
            }
        while(l2){
            NewList->next = new ListNode((l2->val + carry)%10 );
            carry = (l2->val + carry )/10;
            NewList = NewList->next;
            l2 = l2->next;
            }
        if(carry > 0)
            NewList->next =new ListNode(carry);
                                    
        return p->next;
    }
};
