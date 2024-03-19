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
    public ListNode swapPairs(ListNode head) {
        ListNode dummynode = new ListNode(0, head);
        if(head == null || head.next == null){
            return head;
        }
        ListNode pre = dummynode;
        ListNode cur = pre.next;
        ListNode tail = cur.next;
        while(tail != null){
            cur.next = tail.next;
            tail.next = cur;
            pre.next = tail;
            if(cur.next == null || tail.next == null){
                break;
            }
            else{
                pre = cur;
                cur = cur.next;
                tail = cur.next;
            }
        
        }
        return dummynode.next;
    }
}

// 递归版本
// class Solution {
//     public ListNode swapPairs(ListNode head) {
//         // base case 退出提交
//         if(head == null || head.next == null) return head;
//         // 获取当前节点的下一个节点
//         ListNode next = head.next;
//         // 进行递归
//         ListNode newNode = swapPairs(next.next);
//         // 这里进行交换
//         next.next = head;
//         head.next = newNode;

//         return next;
//     }
// } 