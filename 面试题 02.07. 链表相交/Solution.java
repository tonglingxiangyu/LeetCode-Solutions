/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int a = 0, b = 0;
        ListNode pa = headA, pb = headB;
        while(pa != null){
            pa = pa.next;
            a++;
        }
        while(pb != null){
            pb = pb.next;
            b++;
        }
        
        if(pa != pb){
            return null;
        }
        pa = headA;
        pb = headB;
        if(a < b){
            for(int i = 0; i < b - a; i++){
                pb = pb.next;
            }
        }
        if(a > b){
            for(int i = 0; i < a - b; i++){
                pa = pa.next;
            }
        }
        while(pa != pb){
            pa = pa.next;
            pb = pb.next;
        }
        return pa;
        
    }
}