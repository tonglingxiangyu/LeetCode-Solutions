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
    ListNode* swapPairs(ListNode* head) {
        // if(head == nullptr || head->next == nullptr) return head;
        ListNode* res = new ListNode();
        res->next = head; // 新建一个节点来指向答案的节点用于最后的return
        ListNode* prev = res; // 用三个指针实现节点交换
        while(prev->next && prev->next->next){
            ListNode* p = prev->next;
            ListNode* q = prev->next->next;
            p->next = q->next;
            q->next = p;
            prev->next = q;
            prev = p;
        }

        return res->next;
    }
};