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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 这题更简洁的解法可以用递归，我用了最笨的方法
        ListNode* a = list1;
        ListNode* b = list2;
        ListNode* res = new ListNode(-1);
        ListNode* c = res;
        while(a != nullptr || b != nullptr){
            if(a == nullptr){
                while(b != nullptr){
                    c->next = b;
                    c = c->next;
                    b = b->next;
                }
            }
            else if(b == nullptr){
                while(a != nullptr){
                    c->next = a;
                    c = c->next;
                    a = a->next;
                }
            }
            else if(a->val >= b->val){
                c->next = b;
                c = c->next;
                b = b->next;
              
            }
            else if(a->val < b->val){
                c->next = a;
                c = c->next;
                a = a->next;
             
            }
        }
        res = res->next;
        return res;
    }
};