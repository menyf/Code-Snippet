/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rt = new ListNode(0);
        ListNode* now = rt;
        bool flag = false;
        while(1){
            int dig = (l1==NULL?0:l1->val) + (l2==NULL?0:l2->val) + (flag?1:0);
            flag = dig >= 10;
            now->val = dig % 10;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
            if(l1 == NULL && l2 == NULL && !flag) break;
            now->next = new ListNode(0);
            now = now->next;
        }

        return rt;
    }
};
