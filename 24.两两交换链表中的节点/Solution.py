# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummynode = ListNode()
        dummynode.next = head
        if head == None or head.next == None:
            return head
        pre = dummynode
        cur = pre.next
        tail = cur.next
        while tail:
            cur.next = tail.next
            tail.next = cur
            pre.next = tail
            if cur.next == None or tail.next == None:
                break
            else:
                pre = cur
                cur = cur.next
                tail = cur.next
        return dummynode.next
        