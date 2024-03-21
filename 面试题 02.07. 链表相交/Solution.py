# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        a = 0
        b = 0
        pa = headA
        pb = headB
        while pa:
            pa = pa.next
            a += 1
        while pb:
            pb = pb.next
            b += 1

        if pa != pb:
            return None
        pa = headA
        pb = headB
        if a < b:
            for _ in range(b-a):
                pb = pb.next   
        if a > b:
            for _ in range(a-b):
                pa = pa.next  
        while pa != pb:
            pa = pa.next
            pb = pb.next
        return pa
