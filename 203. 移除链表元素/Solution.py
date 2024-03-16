# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # 可以添加一个虚拟节点dummynode来使得删除头节点的操作与后面的操作一致，最后返回dummynode.next即可
        while head != None and head.val == val:
            head = head.next
        if head == None:
            return head
        p = head
        q = p.next
        while q:
            if q.val == val:
                p.next = q.next
                q = p.next
            else:
                p = q
                q = q.next
        return head