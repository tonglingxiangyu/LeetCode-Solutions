/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while(head != null && head.val == val){
            head = head.next;
        }
        if(head == null){
            return head;
        }
        ListNode p = head;
        ListNode q = p.next;
        while(q != null){
            if(q.val == val){
                p.next = q.next;
                q = p.next;
            }
            else{
                p = q;
                q = q.next;
            }
        }
        return head;
    }
}